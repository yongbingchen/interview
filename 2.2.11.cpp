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
		bool is_list_circled(list_node *h)
		{
			list_node *slow, *fast;

			slow = fast = h;

			while(fast != nullptr && fast->next != nullptr) {
				slow = slow->next;
				fast = fast->next->next;
				if (slow == fast)
					return true;
			}

			return false;
		}

		list_node *build_list(vector <int> array)
		{
			list_node dummy_head(-1);
			list_node *p = &dummy_head;

			for (const auto a : array) {
				p->next = new list_node(a);
				p = p->next;
			}
			return dummy_head.next;
		}
};

int main(int argc, char **argv)
{
	vector <int> array = {1, 2, 3, 4, 5, 6, 7};
	solution a;

	list_node *h = a.build_list(array);

	list_node *p = h, *q;
	for (int i = 0; i < 3; i++) {
		p = p->next;
	}

	q = p;
	for (int i = 0; i < 3; i++)
		q = q->next;

	q->next = p;

	cout << "is list cycled " << a.is_list_circled(h) << endl;

}
