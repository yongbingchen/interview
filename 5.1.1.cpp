#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct tree_node {
	char val;
	tree_node* left;
	tree_node* right;
	tree_node(char x) : val(x), left(nullptr), right(nullptr)
	{}
};

void create_from_preorder_traversal(tree_node *root, const string &traversal, int& index) {
	if (traversal[index] == '#') {
		root->left = root->right = NULL;
		return;
	}

	root->left = new tree_node(traversal[index + 1]);
	create_from_preorder_traversal(root->left, traversal, ++index);
	root->right = new tree_node(traversal[index + 1]);
	create_from_preorder_traversal(root->right, traversal, ++index);
}

void preorder_traversal(tree_node *root) {
	if (root->left == NULL) {
		cout << "leaf node has val " << root->val << endl;
		return;
	}
	cout << "non-leaf node has val " << root->val << endl;
#if 0
	cout << "its left child has val " << root->left->val << endl;
	cout << "its right child has val " << root->right->val << endl;
#endif
	preorder_traversal(root->left);
	preorder_traversal(root->right);
}

class solution {
	public:
		vector <char> preorder_traversal(const tree_node *root)
		{
			stack <const tree_node *> stk;
			vector <char> result;

			if (root != nullptr) stk.push(root);

			while(!stk.empty()) {
				const tree_node *p = stk.top();
				stk.pop();
				result.push_back(p->val);

				//access right later, so right child push first
				if (p->right != nullptr)
					stk.push(p->right);
				//here is not if -> else if, otherwise half tree will be lost
				if (p->left != nullptr)
					stk.push(p->left);
			}

			return result;
		}
};

int main(int argc, char **argv)
{
	string traversal = "123##4##5#6#78##9##";
/*					      1
 *			                    /   \
 *					   2     5
 *		     		          / \   / \
 *		     		  	 3   4  #  6
 *	       			        / \ / \   / \
 *	     	   	     	       #  # #  # #   7
 *	     					     / \
 *	     					    8   9
 *                                                 /\   /\
 *                                                #  #  # #
 * */


	int index = 0;
	tree_node *root = new tree_node(traversal[index]);
	create_from_preorder_traversal(root, traversal, index);

	solution a;
	vector <char> result = a.preorder_traversal(root);

	for (auto i : result)
		cout << i << ", ";
	cout << endl;
}
