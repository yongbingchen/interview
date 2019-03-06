#include <iostream>
#include <string>
#include <vector>
#include <stack>

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
		vector <char> inorder_traversal(tree_node *root)
		{
			vector <char> result;
			stack <tree_node *> s;

			tree_node *p = root;
			// when stack is empty, and p is not null, if we stop here
			// the whole right subtree will be missed.
			while(!s.empty() || p != nullptr) {
				//walk down to the leftest.
				while (p != nullptr) {
					s.push(p);
					p = p->left;
				}

				if (!s.empty()) {
					p = s.top();
					s.pop();
					result.push_back(p->val);
					//after visit curr node, try vist its right child.
					p = p->right;
				}
			}
			return result;
		}

		void inorder_traversal_recursive(const tree_node *root, vector <char> &result)
		{
			if (root == nullptr)
				return;

			inorder_traversal_recursive(root->left, result);
			result.push_back(root->val);
			inorder_traversal_recursive(root->right, result);
		}

		vector <char> preorder_traversal(const tree_node *root)
		{
			stack <const tree_node *> stk;
			vector <char> result;

			if (root != nullptr) stk.push(root);

			while(!stk.empty()) {
				const tree_node *p = stk.top();
				stk.pop();
				result.push_back(p->val);

				if (p->right != nullptr)
					stk.push(p->right);
				if (p->left != nullptr)
					stk.push(p->left);
			}

			return result;
		}


		void build_tree(tree_node *root, const string &preorder_traversal, int &index)
		{
			if (preorder_traversal[index] == '#')
				return;

			root->left = new tree_node(preorder_traversal[index + 1]);
			//CAUTION!, use below method will lose all leaf node (with value '#')
			//root->left = build_tree(root->left, preorder_traversal, ++index);
			build_tree(root->left, preorder_traversal, ++index);
			root->right = new tree_node(preorder_traversal[index + 1]);
			build_tree(root->right, preorder_traversal, ++index);
		}
};

int main(int argc, char **argv)
{
	solution a;
	const string preorder_traversal = "123##4##5#6#78##9##";

	int index = 0; /*!CAUTION, illegal to pass a constant to a int reference*/
	tree_node *root = new tree_node(preorder_traversal[index]);
	a.build_tree(root, preorder_traversal, index);

	vector <char> result = a.inorder_traversal(root);
	for (auto c : result)
		cout << c;
	cout << endl;

	vector <char> result2;
	a.inorder_traversal_recursive(root, result2);
	for (auto c : result2)
		cout << c;
	cout << endl;

	vector <char> result3;
	result3 = a.preorder_traversal(root);
	for (const auto &c : result3)
	       cout << c;
	cout << endl;
}
