#include <iostream>
#include <vector>

using namespace std;

struct node {
	int val;
	vector <node *> next;
	node(int x) : val(x)
	{}
};

class solution {
public:
	void delete_zero(node *root, node *parent)
	{
		if (root == nullptr)
			return;

		if (root->val == 0) {
			if (parent == nullptr) {
				select_non_zero_child_as_parent();
			}
			for (auto &n : root->next)
				parent->next.push_back(n);
			delete root;
			delete_zero(parent, nullptr);
			return;
		}

		for (auto &n : root->next) {
			if (n != nullptr) {
				delete_zero(n, root);
			}
		}
	}
};
