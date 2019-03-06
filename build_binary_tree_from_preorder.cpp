#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct node {
	int val;
	node *left;
	node *right;
	node(int x) : val(x), left(nullptr), right(nullptr)
	{}
};

class tree {
public:
	node *build_tree(vector <int> &preorder, int &idx) //WARNING! do not forget to use reference of idx as param, BUG!
	{
		if (preorder[idx] == INT_MIN)
			return nullptr;

		node *root = new node(preorder[idx]);
		int val = preorder[idx];
		idx++; //now idx point to root's left subtree's root;
		root->left = build_tree(preorder, idx);
		idx++; //after the end of the left subtree, the next is the root's right subtree's root;
		root->right = build_tree(preorder, idx);
		//no need to ++idx after this! recursive call will exhaust all right subtree node by itself.

		return root;
	}

	void preorder(node *root, vector <int> &result)
	{
		if (root == nullptr) {
			result.push_back(INT_MIN);
			return;
		}

		result.push_back(root->val);
		preorder(root->left, result);
		preorder(root->right, result);
	}

};

int main(int argc, char **argv)
{
	vector <int> preorder = {5, 3, 1, INT_MIN, INT_MIN, INT_MIN, 2, 6, INT_MIN, INT_MIN, 1, INT_MIN, INT_MIN};

	tree t;
	int idx = 0;
	node *root = t.build_tree(preorder, idx);
	vector <int> result;
	t.preorder(root, result);
	for (auto &i : result)
		cout << i << ", ";
	cout << endl;
}

