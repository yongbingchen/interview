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
		node *reverse(node *h, int m, int n)
		{
			node *p = h;
			node *insert_pos = h;

			for (int i = 0; i < m - 1; i++) {
				if (p == nullptr)
					return nullptr;
				insert_pos = p;
				p = p->next;
			}

			for (int i = 0; i < n - m; i++) {
				node *to_insert = p->next;
				if (to_insert == nullptr)
					return nullptr;
				p->next = to_insert->next;

				to_insert->next = insert_pos->next;
				insert_pos->next = to_insert;
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
	vector <int> v = {1, 2, 3, 4, 5, 6, 7, 8};
	node *l = s.build_list(v);

	node *result = s.reverse(l, 2, 5);

	while(result != nullptr && result->val >= 0) {
		cout << result->val;
		result = result->next;
	}
	cout << endl;
	exit(EXIT_SUCCESS);
}
