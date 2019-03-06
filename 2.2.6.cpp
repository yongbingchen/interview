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
		node *rotate_list(node *h, int k)
		{
			node *p = h;
			node *prev, *tail;
			int len = 0;
			//CAUTION! this question does not require one pass.
			while(p != nullptr) {
				len++;
				prev = p;
				p = p->next;
			}
			tail = prev;

			//let p walk from head for len - k nodes, point to the target new head node
			p = h;
			for (int i = 0; i < len - k; i++) {
				prev = p;
				p = p->next;
			}

			//link the list as a loop
			tail->next = h;

			//let new head point to the len -k node
			h = p;
			//break loop from prev of len - k node
			prev->next = nullptr;

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
	vector <int> v = {1, 2, 3, 4, 5, 6, 7, 8};
	node *l = s.build_list(v);

	node *result = s.rotate_list(l, 2);

	while(result != nullptr) {
		cout << result->val;
		result = result->next;
	}
	cout << endl;
	exit(EXIT_SUCCESS);
}
