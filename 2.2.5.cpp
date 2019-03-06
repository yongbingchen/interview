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
		node *remove_duplicate(node *h)
		{
			if (h == nullptr || h->next == nullptr)
				return h;

			/*simplify the case, by only handle the duplicate node from list head*/
			if (h->val == h->next->val) {
				node *p = h->next;
				while(p != nullptr &&h->val == p->val) {
					node *tmp = p;
					p = p->next;
					//CAUTION! remember to delete the node!
					delete tmp;
				}
				delete h;

				/*let p point to first not equal to head node, delete all nodes before it*/
				return remove_duplicate(p);
			}
			else {
				h->next = remove_duplicate(h->next);
				return h;
			}
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
	vector <int> v = {1, 1, 1, 2, 2, 3, 4, 4, 4, 5};
	node *l = s.build_list(v);

	node *result = s.remove_duplicate(l);

	while(result != nullptr && result->val >= 0) {
		cout << result->val;
		result = result->next;
	}
	cout << endl;

	exit(EXIT_SUCCESS);
}
