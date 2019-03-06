#include <iostream>
#include <vector>

using namespace std;

struct node {
	int val;
	node *next;
	node (int x) : val(x)
	{}
};

class solution {
	public:
		node *detect_loop(node *h)
		{
			node *fast = h;
			node *slow = h;

			while(fast != nullptr && fast->next != nullptr && slow != nullptr) {
				/*WRONG! this will not move further, because they are still the same as head;
				  if (fast == slow)
				  return slow;
				  */

				fast = fast->next->next;
				slow = slow->next;
				if (fast == slow)
					return slow;
			}

			return nullptr;
		}

		node *detect_loop_entry(node *h) {

			node *meet_point = detect_loop(h);

			if (meet_point == nullptr)
				return nullptr;

			node *loop_entry = detect_loop_entry(h, meet_point);

			return loop_entry;
		}

		node *make_loop(node *h, const int val)
		{
			if (h == nullptr)
				return nullptr;

			node *p = h;
			while(p != nullptr && p->next != nullptr)
				p = p->next;

			node *q = h;
			while(q != nullptr && q->val != val)
				q = q->next;

			if (p == nullptr)
				return nullptr;

			p->next = q;

			return h;
		}

		node *build_list(const vector <int> &array)
		{
			node dummy_head(-1);

			node *p = &dummy_head;

			for (const auto &i : array) {
				p->next = new node(i);
				p = p->next;
			}
			return dummy_head.next;
		}

	private:
		node *detect_loop_entry(node *h, node *meet_point)
		{
			node *p1 = h, *p2 = meet_point;
			/*
			 * 1. let x = distance(head, loop_entry)
			 * 2. let y = distance(loop_entry, meet_point)
			 * 3. let r = len of loop.
			 * 4. when slow and fast pointer meet at meet_point:
			 * 4.1 let s = distance of slow pointer traveled, it has below relation:
			 *	s = x + y;
			 * 4.2 let f = distance of fast pointer traveled, it traveled
			 *     twice the distance of s:
			 *              f = 2 * s;
			 *     and it must traveled n times within the circle from
			 *     meet_point:
			 *		f = s + n * r
			 *	which turn into s = n * r;
			 *	while s = x + y, then
			 *	x + y = n * r;
			 *	x = n * r - y;
			 *
			 * 5. let p1 travel from head for x steps, p2 start from meet_point travel x steps too,
			 *    then p2 traveled to the point where it loops n * r round
			 *    in the loop, and step back y steps, which is exact the
			 *    same place as p1, so when p1 meet p2, that's the
			 *    loop_entry.
			 */

			while(p1 != nullptr && p2 != nullptr) {
				p1 = p1->next;
				p2 = p2->next;
				if (p2 == p1)
					return p1;
			}

			return nullptr;
		}
};

int main(int argc, char **argv)
{

	const vector <int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	solution s;

	node *h = s.build_list(array);
	node *p =h;
	while (p != nullptr) {
		cout << p->val << ", ";
		p = p->next;
	}
	cout << endl;

	h = s.make_loop(h, 10);
	p =h;
	int i = 0;
	cout << "after add loop:" << endl;
	while (p != nullptr && i++ < 30) {
		cout << p->val << ", ";
		p = p->next;
	}
	cout << endl;


	node *meet_point = s.detect_loop(h);
	if (meet_point == nullptr)
		cout << "no loop found in list" << endl;
	else {
		cout << "found loop, meet point value " << meet_point->val << endl;
		node * loop_entry = s.detect_loop_entry(h);
		cout << "loop start at node value " << loop_entry->val << endl;
	}
	exit(EXIT_SUCCESS);
}

