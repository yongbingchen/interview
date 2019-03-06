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
		node * remove_nth_from_end(node *h, int n)
		{
			node *p, *q;

			p = h;
			for (int i = 0; i < n; i++) {
				if (p == nullptr)
					return nullptr;
				p = p->next;
			}

			q = h;
			while(p->next != nullptr) {
				p = p->next;
				q = q->next;
			}

			node *tmp = q->next;
			q->next = tmp->next;
			delete tmp;

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

	node *result = s.remove_nth_from_end(l, 2);

	while(result != nullptr && result->val >= 0) {
		cout << result->val;
		result = result->next;
	}
	cout << endl;
	exit(EXIT_SUCCESS);
}
