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
		node * build_list(vector <int> &a)
		{
			node dummy_head(-1);
			node *p = &dummy_head;

			for (auto &i : a) {
				p->next = new node(i);
				p = p->next;
			}

			return dummy_head.next;
		}

		node *add_two_nums(node *h1, node *h2)
		{
			node dummy_head(-1);
			node *result = &dummy_head;

			int carry = 0;
			while(h1 != nullptr || h2 != nullptr) {
				int digit1 = h1 == nullptr ? 0 : h1->val;
				int digit2 = h2 == nullptr ? 0 : h2->val;

				int digit = digit1 + digit2 + carry;
				carry = digit / 10;
				result->next = new node(digit % 10);

				result = result->next;
				if (h1 != nullptr)
					h1 = h1->next;
				if (h2 != nullptr)
					h2 = h2->next;
			}

			if (carry != 0)
				result->next = new node(carry);

			return dummy_head.next;
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <int> v1 = {1, 2, 3, 4, 5, 6, 7, 8};
	vector <int> v2 = {8, 8, 8, 2};
	node *l1 = s.build_list(v1);
	node *l2 = s.build_list(v2);

	node *result = s.add_two_nums(l1, l2);

	while(result != nullptr && result->val >= 0) {
		cout << result->val;
		result = result->next;
	}
	cout << endl;
	exit(EXIT_SUCCESS);
}
