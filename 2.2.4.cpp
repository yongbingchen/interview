#include <iostream>
#include <vector>

using namespace std;

struct list_node {
	int val;
	struct list_node *next;
	list_node(int x) : val(x), next(nullptr)
	{}
};

class solution {
	public:
		list_node *remove_duplicated(list_node *h)
		{
			if (h == nullptr)
				return h;

			list_node *prev = h;
			for (list_node *cur = prev->next; cur != nullptr; ) {
				if (prev->val == cur->val) {
					prev->next = cur->next;
					delete cur;
					prev = prev->next;
					if (prev == nullptr)
						break;
					cur = prev->next;

				}
				else {
					prev = cur;
					cur = cur->next;
				}
			}

			return h;
		}

		list_node *build_list_from_array(vector <int> &array)
		{
			list_node dummy_head(-1);
			list_node *p = &dummy_head;

			for (auto &a : array) {
				p->next = new list_node(a);
				p = p->next;
			}

			return dummy_head.next;
		}
};

int main(int argc, char **argv)
{
	solution a;
	vector <int>  array = {1, 1, 2, 3, 3};

	list_node *h = a.build_list_from_array(array);

	h = a.remove_duplicated(h);

	while(h != nullptr) {
		cout << h->val;
		h = h->next;
	}
	cout << endl;
}
