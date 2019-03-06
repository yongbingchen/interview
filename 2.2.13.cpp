#include <iostream>
#include <vector>

using namespace std;

struct list_node {
	int val;
	list_node *next;
	list_node(int x) : val(x), next(nullptr)
	{}
};

class solution {
	public:
		list_node *reorder_list(list_node *h)
		{
			list_node *l2, *curr = h;

			int len = 0;
			while(curr != nullptr) {
				len++;
				curr= curr->next;
			}

			curr = h;
			for (int i = 0; i < len / 2 - 1; i++)
				curr = curr->next;

			//build second half list
			l2 = curr->next;

			//cut off from middle
			curr->next = nullptr;

			l2 = reverse_list(l2);

			h = merge_list(h, l2);

			return h;
		}

		list_node *build_list(vector <int> array)
		{
			list_node dummy_head(-1);
			list_node *p = &dummy_head;

			for (const auto &a : array) {
				p->next = new list_node(a);
				p = p->next;
			}
			return dummy_head.next;
		}
	private:
		list_node *merge_list(list_node *h1, list_node *h2) {
			list_node dummy_head(-1);
			list_node *p = &dummy_head;
			list_node *next1, *next2;

			while(h1 != nullptr && h2 !=  nullptr) {
				next1 = h1->next;
				next2 = h2->next;

				p->next = h1;
				p = p->next;
				p->next = h2;
				p = p->next;

				h1 = next1;
				h2 = next2;
			}

			while(h1 != nullptr) {
				p->next = h1;
				p = p->next;
				h1 = h1->next;
			}
			while(h2 != nullptr) {
				p->next = h2;
				p = p->next;
				h2 = h2->next;
			}

			p->next = nullptr;

			return dummy_head.next;
		}

		/*!!!! this is important to master!*/
		list_node *reverse_list(list_node *h)
		{
			list_node *new_head = h;
			list_node *old_head = h;
			while(old_head->next != nullptr) {
				list_node *to_insert = old_head->next;
				old_head->next = to_insert->next;
				to_insert->next = new_head;
				new_head = to_insert;
			}
			return new_head;
		}
};

int main(int argc, char **argv)
{
	//vector <int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector <int> array = {1, 2, 3, 4, 5, 6, 7, 8};

	solution a;

	list_node *h = a.build_list(array);

	h = a.reorder_list(h);

	while(h != nullptr) {
		cout << h->val;
		/* skip delete h step for simplicity*/
		h = h->next;
	}
	cout << endl;
}

