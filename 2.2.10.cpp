#include <iostream>
#include <vector>

using namespace std;

struct node {
	int val;
	node *next;
	node *random;
	node(int x) : val(x), next(nullptr), random(nullptr)
	{}
};

class solution {
	public:
		node *deep_copy(node *h)
		{
			//1. copy each node, with value only, then insert it next to original list.
			node *p = h;
			while(p != nullptr) {
				node *copy = new node(p->val);
				copy->next = p->next;
				p->next = copy;
				p = p->next->next;
			}
			//2. the random pointer at original node should still be valid after step 1,
			//   so try to copy original's random pointer's next as new copy's random pointer.
			p = h;
			while(p !=nullptr) {
				p->next->random = p->random->next;
				p = p->next->next;
			}
			//3. split the list to two, return the copy one.
			node dummy_head(-1);
			node *q = &dummy_head;
			p = h;
			while(p !=nullptr && p->next != nullptr) {
				q->next = p->next;
				q = q->next;
				p = p->next->next;
			}
			q->next = nullptr;

			return dummy_head.next;
		}

		node * build_list(vector <int> &v)
		{
			node dummy_head(-1);
			node *h = &dummy_head;
			for (auto &i : v) {
				h->next = new node(i);
				h = h->next;
			}
			node *p =dummy_head.next;
			while(p != nullptr && p->next !=nullptr && p->next->next != nullptr) {
				p->random = p->next->next;
				p = p->next;
			}
			if(p != nullptr && p->next !=nullptr && p->next->next == nullptr) {
				p->random = dummy_head.next->next;
				p = p->next;
			}
			p->random = dummy_head.next;

			return dummy_head.next;
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <int> v = {1, 2, 3, 4, 5, 6, 7, 8};
	node *l = s.build_list(v);
	node *result = l;
	while(result != nullptr && result->val >= 0) {
		cout << "before deep copy, node val " << result->val << ", randome node val " << result->random->val << endl;
		result = result->next;
	}

	result = s.deep_copy(l);

	while(result != nullptr && result->val >= 0) {
		cout << "after deep copy, node val " << result->val << ", randome node val " << result->random->val << endl;
		result = result->next;
	}
	exit(EXIT_SUCCESS);
}
