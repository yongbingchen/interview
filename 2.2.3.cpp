#include <iostream>
#include <vector>

using namespace std;

struct node {
	int val;
	node *next;
	node(int x) : val(x), next(nullptr)
	{}
};

class solution {
	public:
		node *partition_list(node *h, int target)
		{
			node dummy_head_less(-1);
			node dummy_head_larger(-1);
			node *less = &dummy_head_less;
			node *larger = &dummy_head_larger;

			while(h != nullptr) {
				if (h->val < target) {
					less->next = h;
					less = less->next;
				}
				else {
					larger->next = h;
					larger = larger->next;
				}
				h = h->next;
			}

			less->next = dummy_head_larger.next;
			larger->next = nullptr;//CAUTION! larger sub list tail may not be the original tail.

			return dummy_head_less.next;
		}

		node *partition(node *h, int x)
		{
			//let h2 point to head of second part.
			node *h2 = h;
			node *tail1;
			while(h2->val < x) {
				tail1 = h2;
				h2 = h2->next;
			}

			node *prev = h2;
			node *p = prev->next;
			while(p != nullptr) {
				if (p->val >= x) {
					prev = p;
					p = p->next;
				}
				else {
					//break node p from its point.
					node *t = p;
					prev->next = p->next;
					p = prev->next;

					//put it at the end of first part
					tail1->next = t;
					t->next = h2;
					tail1 = t;
				}
			}
			return h;
		}


		node * build_list(vector <int> &v)
		{
			node dummy_head(-1);
			node *h = &dummy_head;
			for (auto &i : v) {
				h->next = new node(i);
				h = h->next;
			}
			return dummy_head.next;
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <int> v = {1, 4, 3, 2, 5, 2, 7, 8};
	node *l = s.build_list(v);

	node *result = s.partition_list(l, 3);
	while(result != nullptr && result->val >= 0) {
		cout << result->val;
		result = result->next;
	}
	cout << endl;
	exit(EXIT_SUCCESS);
}
