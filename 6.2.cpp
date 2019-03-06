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
	node *merge_sorted_list(node *l1, node *l2)
	{
		node dummy_head(-1);
		node *p = &dummy_head;
		node *next;

		if (l1 == nullptr)
			return l2;

		if(l2 == nullptr)
			return l1;

		if (l1->val < l2->val) {
			p->next = l1;
			p = p->next;
			p->next = merge_sorted_list(l1->next, l2);
		}
		else {
			p->next = l2;
			p = p->next;
			p->next = merge_sorted_list(l1, l2->next);
		}

		return dummy_head.next;
	}

	node * build_list(const vector <int> &a)
	{
		node dummy_head(-1);
		node *p = &dummy_head;

		for (const auto &i : a) {
			p->next = new node(i);
			p = p->next;
		}

		p->next = nullptr;
		return dummy_head.next;
	}
};


int main(int argc, char **argv)
{
	const vector <int> v1 = {1, 3, 5, 7, 10, 12, 14, 16};
	const vector <int> v2 = {2, 4, 6, 8, 9, 11, 13, 15, 17, 19, 21, 23, 25};

	solution s;
	node *l1 = s.build_list(v1);
	node *l2 = s.build_list(v2);

	node *ret = s.merge_sorted_list(l1, l2);

	while(ret != nullptr) {
		cout << ret->val << " ,";
		ret = ret->next;
	}
	cout << endl;
}

