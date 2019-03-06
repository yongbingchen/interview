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
	node *merge_sort(node *l)
	{
		if (l == nullptr)
			return nullptr;

		if (l->next == nullptr)
			return l;

		node *p = l;
		int len = get_len(l);
		if (len == 2) {
			if (l->val > l->next->val) {
				l = swap_len2_list(l);
			}
			return l;
		}

		int mid = len / 2;
		node *left, *right;
		break_list(l, mid, &left, &right);

		left = merge_sort(left);
		right = merge_sort(right);

		return merge_sorted_list(left, right);
	}

	node *build_list(const vector <int> &v)
	{
		node dummy_head(-1);
		node *p = &dummy_head;

		for (const auto &i : v) {
			p->next = new node(i);
			p = p->next;
		}

		return dummy_head.next;
	}

private:
	int get_len(node *l)
	{
		int len = 0;
		while(l != nullptr) {
			len++;
			l = l->next;
		}

		return len;
	}

	node *swap_len2_list(node *l)
	{
		node *p = l->next;

		p->next = l;
		l->next = nullptr;

		return p;
	}

	void break_list(node *l, const int mid, node **left, node **right)
	{
		*left = l;

		for (int i = 0; i < mid; i++)
			l = l->next;

		*right = l->next;
		l->next = nullptr;
	}

	node *merge_sorted_list(node *l1, node *l2)
	{
		if (l1 == nullptr)
			return l2;

		if (l2 == nullptr)
			return l1;

		node dummy_head(-1);
		node *p = &dummy_head;

		if (l1->val > l2->val) {
			p->next = l2;
			p = p->next;
			p->next = merge_sorted_list(l1, l2->next);
		}
		else {
			p->next = l1;
			p = p->next;
			p->next = merge_sorted_list(l1->next, l2);
		}

		return dummy_head.next;
	}
};

int main(int argc, char **argv)
{
	const vector <int> v = {9, 1, 11, 5, 2, 6, 7, 8, 10, 4, 3, 12, 0};

	solution s;

	node *l = s.build_list(v);

	node *ret = s.merge_sort(l);

	while(ret != nullptr) {
		cout << ret->val << ", ";
		ret = ret->next;
	}
	cout << endl;

	exit(EXIT_SUCCESS);
}

