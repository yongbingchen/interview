#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
struct node {
	char val;
	node *left;
	node *right;
	node(int x) : val(x), left(nullptr), right(nullptr)
	{}
};


class solution {
	public:
		vector <char> preorder(node *root)
		{
			stack <node *> stk;
			if (root)
				stk.push(root);
			vector <char> ret;
			while(!stk.empty()) {
				node *p = stk.top();
				stk.pop();
				ret.push_back(p->val);

				if (p->right)
					stk.push(p->right);
				if (p->left)
					stk.push(p->left);
			}
			return ret;
		}

		vector <char> inorder(node *root)
		{
			stack <node *> stk;
			vector <char> ret;

			node *p = root;
			while(!stk.empty() || p != nullptr) {
				if (p != nullptr) {
					stk.push(p);
					p = p->left;
				}
				else if (!stk.empty()) {
					p = stk.top();
					stk.pop();
					ret.push_back(p->val);
					p = p->right;
				}
			}

			return ret;
		}

		vector <char> postorder(node *root)
		{
			stack <node *> stk;
			vector <char> ret;
			if (root != nullptr)
				stk.push(root);

			node *last_visit = nullptr;
			while(!stk.empty()) {
				node *p = stk.top();
				if (p->right == nullptr && p->left == nullptr ||
					p->right == nullptr && last_visit == p->left ||
					last_visit == p->right) {
					ret.push_back(p->val);
					stk.pop();
					last_visit = p;
				}
				else {
					if (p->right)
						stk.push(p->right);
					if (p->left)
						stk.push(p->left);
				}
			}

			return ret;
		}

		vector <char> level_traversal(node *root)
		{
			queue <node *> q;
			vector <char> ret;

			if (root != nullptr)
				q.push(root);

			while(!q.empty()) {
				node *p = q.front();
				ret.push_back(p->val);
				q.pop();

				if (p->left != nullptr)
					q.push(p->left);

				if (p->right != nullptr)
					q.push(p->right);
			}

			return ret;
		}
};


void create_from_preorder_traversal(node *root, const string &traversal, int& index) {
	if (traversal[index] == '#') {
		root->left = root->right = NULL;
		return;
	}

	root->left = new node(traversal[index + 1]);
	create_from_preorder_traversal(root->left, traversal, ++index);
	root->right = new node(traversal[index + 1]);
	create_from_preorder_traversal(root->right, traversal, ++index);
}

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
	node *root = new node(traversal[index]);
	create_from_preorder_traversal(root, traversal, index);

	solution a;
	vector <char> result = a.preorder(root);
	for (auto i : result)
		cout << i << ", ";
	cout << endl;

	result.clear();
	result = a.inorder(root);
	for (auto i : result)
		cout << i << ", ";
	cout << endl;

	result.clear();
	result = a.postorder(root);
	for (auto i : result)
		cout << i << ", ";
	cout << endl;

	result.clear();
	result = a.level_traversal(root);
	for (auto i : result)
		cout << i << ", ";
	cout << endl;
}
