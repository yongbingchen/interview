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
		node *reverse_nodes_in_k_group(node *h, int k)
		{
			node *p = h;
			for (int i = 0; i < k; i++) {
				if (p == nullptr)
					return h;
				p = p->next;
			}

			h = reverse_k_group_at_head(h, k);
			p = h;
			for (int i = 0; i < k - 1; i++)
				p = p->next;
			p->next = reverse_nodes_in_k_group(p->next, k);

			/* WRONG way!
			this way is going to break the list, since 'p' will be changed inside the call.
			for (int i = 0; i < k; i++)
				p = p->next;
			p = reverse_nodes_in_k_group(p, k);
			*/

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
	private:
		node *reverse_k_group_at_head(node *h, int k)
		{
			//NOTE! reverse only need apply to k -1 nodes (p node does not need move)
			node *new_head = h;
			node *old_head = h;
			for (int i = 1; i < k; i++) {
				node *to_insert = old_head->next;
				//break it from list
				old_head->next = to_insert->next;

				//make it the new_head
				to_insert->next = new_head;
				new_head = to_insert;
			}
			return new_head;
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	node *l = s.build_list(v);

	node *result = s.reverse_nodes_in_k_group(l, 3);

	while(result != nullptr && result->val >= 0) {
		cout << result->val;
		result = result->next;
	}
	cout << endl;
	exit(EXIT_SUCCESS);
}
