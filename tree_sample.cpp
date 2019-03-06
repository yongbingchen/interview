#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct node {
	int val;
	node *left;
	node *right;
	node(int x) : val(x), right(nullptr), left(nullptr)
	{}
};

class solution {
public:
	node *build_tree(vector <int> &preorder, vector <int> &inorder)
	{
		return build_tree(preorder.begin(), preorder.end(),
				inorder.begin(), inorder.end());

	}

	void inorder(node *root, vector <int> &result)
	{
		if (root == nullptr)
			return;

		stack <node *> stk;
		node *p = root;

		while(!stk.empty() || p != nullptr) {
			if (p != nullptr) {
				stk.push(p);
				p = p->left;
			}
			else {
				p = stk.top();
				result.push_back(p->val);
				stk.pop();

				p = p->right;
			}
		}
	}
	void preorder(node *root, vector <int> &result)
	{
		if (root == nullptr)
			return;

		stack <node *> stk;

		stk.push(root);
		while(!stk.empty()) {
			node *p = stk.top();
			result.push_back(p->val);
			stk.pop();

			if (p->right)
				stk.push(p->right);
			if (p->left)
				stk.push(p->left);
		}
	}


	void postorder(node *root, vector <int> &result)
	{
		if (root == nullptr)
			return;

		stack <node *> stk;
		stk.push(root);

		node *prev = nullptr;
		while(!stk.empty()) {
			node *p = stk.top();
			if (p->left == nullptr && p->right == nullptr ||
					p->right == nullptr && prev == p->left ||
					prev == p->right) {
				result.push_back(p->val);
				stk.pop();
				prev = p;
			} else {
				if (p->right)
					stk.push(p->right);
				if (p->left)
					stk.push(p->left);
			}
		}
	}

private:
	template <typename forward_iterator>
		node *build_tree(forward_iterator p_start, forward_iterator p_end,
				forward_iterator i_start, forward_iterator i_end)
		{
			if (p_start == p_end)
				return nullptr;

			node *root = new node(*p_start);

			forward_iterator root_in_pos = find(i_start, i_end, *p_start);
			int left_size = distance(i_start, root_in_pos);

			root->left = build_tree(next(p_start),
					next(p_start, left_size + 1),
					i_start,
					root_in_pos);

			root->right = build_tree(next(p_start, left_size + 1),
					p_end,
					next(root_in_pos),
					i_end);

			return root;
		}
};

int main(int argc, char **argv)
{
	solution s;

	/*		       4
	 *		      /  \
	 *		     2     6
	 *		    / \   / \
	 *                 1   3 5   7
	 * */
	vector <int> preorder = {4, 2, 1, 3, 6, 5, 7};
	vector <int> inorder = {1, 2, 3, 4, 5, 6, 7};

	node *root = s.build_tree(preorder, inorder);
	vector <int> result;
	s.preorder(root, result);
	cout << "pre order traversal:" << endl;
	for (auto &i : result)
		cout << i;
	cout << endl;

	result.clear();
	s.inorder(root, result);
	cout << "in order traversal:" << endl;
	for (auto &i : result)
		cout << i;
	cout << endl;

	result.clear();
	s.postorder(root, result);
	cout << "post order traversal:" << endl;
	for (auto &i : result)
		cout << i;
	cout << endl;
}
