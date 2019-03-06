#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct tree_node {
	char val;
	tree_node *left;
	tree_node *right;
	tree_node(char x) : val(x), left(nullptr), right(nullptr)
	{}
};

class solution {
	public:
		void recover_bst(tree_node *root)
		{
			if (root == nullptr)
				return;

			vector <char> inorder;
			inorder = inorder_traversal(root);

			vector <char> num_only;
			for (const auto & c : inorder) {
				if (c != '#')
					num_only.push_back(c);
			}

			char first = 0, second = 0;
			for (int i = 0; i < num_only.size() - 1; i++) {
				if (num_only[i] > num_only[i + 1]) {
					if (first == 0)
						first = num_only[i];
					else
						second = num_only[i + 1];
				}
			}

			cout << "first " << first << " second " << second << endl;

			//CAUTION! use recursive trave can also be used to change node value
			//DO NOT USE ITERATE travel unless asked to.
			//swap_node(root, first, second);
			swap_node_recursive(root, first, second);
		}

		vector <char> inorder_traversal(tree_node *root)
		{
			vector <char> result;
			if (!root)
				return result;

			inorder_traversal_priv(root, result);

			return result;
		}

		void build_tree(tree_node *root, const string preorder, int &index)
		{
			if (preorder[index] == '#')
				return;

			index++;
			root->left = new tree_node(preorder[index]);
			build_tree(root->left, preorder, index);
			index++;
			root->right = new tree_node(preorder[index]);
			build_tree(root->right, preorder, index);
		}

	private:
		void swap_node(tree_node *root, char first, char second)
		{
			tree_node *f = nullptr, *s = nullptr;
			stack <tree_node *> stk;

			tree_node *p = root;
			while(!stk.empty() || p != nullptr) {
				if (p != nullptr) {
					stk.push(p);
					p = p->left;
				}
				else if (!stk.empty()) {
					p = stk.top();
					stk.pop();
					if (p->val == first)
						f = p;
					else if (p->val == second)
						s = p;
					p = p->right;
				}
			}

			f->val = second;
			s->val = first;
		}

		void swap_node_recursive(tree_node *root, char first, char second)
		{
			if (!root)
				return;
			swap_node_recursive(root->left, first, second);
			if (root->val == first)
				root->val = second;
			else if (root->val == second)
				root->val = first;
			swap_node_recursive(root->right, first, second);
		}


		void inorder_traversal_priv(tree_node *root, vector <char> &result)
		{
			if (!root)
				return;

			inorder_traversal_priv(root->left, result);
			result.push_back(root->val);
			inorder_traversal_priv(root->right, result);
		}
};

int main(int argc, char **argv)
{
	const string preorder = "421##3##9#6#87##5##";
	solution a;

	int index = 0;
	tree_node *root = new tree_node(preorder[index]);

	a.build_tree(root, preorder, index);

	vector <char> result  = a.inorder_traversal(root);
	for (const auto &c : result)
		cout << c;
	cout << endl;

	a.recover_bst(root);

	vector <char> result2 = a.inorder_traversal(root);
	for (const auto & c : result2)
		cout << c;
	cout << endl;
}
