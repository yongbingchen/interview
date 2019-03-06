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
		node *swap_nodes_in_pair(node *h)
		{
			if (h == nullptr)
				return h;
			if (h->next == nullptr)
				return h;

			node *new_head = h->next;
			h->next = new_head->next;
			new_head->next = h;

			h->next = swap_nodes_in_pair(h->next);

			return new_head;
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
	vector <int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	node *l = s.build_list(v);

	node *result = s.swap_nodes_in_pair(l);

	while(result != nullptr && result->val >= 0) {
		cout << result->val;
		result = result->next;
	}
	cout << endl;
	exit(EXIT_SUCCESS);
}
