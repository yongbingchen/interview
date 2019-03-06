#include <iostream>
#include <vector>

using namespace std;

struct node {
	bool val;
	node *left;
	node *right;
	node(bool x) : val(x), right(nullptr), left(nullptr)
	{}
};

class solution {
public:
	void invert_leaf(node *root, node *leaf)
	{
		vector <node *> path;
		get_path_to_leaf(root, leaf, path);
		for (auto it = path.rbegin(); it != path.rend(); it++) {
			if (*it == leaf)
				(*it)->val ^= (*it)->val;
			else {
				bool left_val = (*it)->left != nullptr ? (*it)->left->val : false;
				bool right_val = (*it)->right != nullptr ? (*it)->right->val : false;
				(*it)->val = left_val & right_val;
			}
		}
	}

	node *build_tree(vector <char> &preorder, int &idx)
	{
		if (idx == preorder.size())
			return nullptr;

		if (preorder[idx] == '#') {
			return nullptr;
		}

		bool val = preorder[idx] == '1' ? true : false;
		node *root = new node(val);
		idx++;
		root->left = build_tree(preorder, idx);
		idx++;
		root->right = build_tree(preorder, idx);
		return root;
	}

	node *get_kth_leaf(node *root, int &k)
	{
		if (root == nullptr)
			return nullptr;
		if (root->left == nullptr && root->right == nullptr)
			k--;
		if (k == 0)
			return root;

		node *ret = get_kth_leaf(root->left, k);
		if (ret != nullptr)
			return ret;
		ret =get_kth_leaf(root->right, k);
		if (ret != nullptr)
			return ret;
		return nullptr;
	}

	void preorder_traversal(node *root)
	{
		if (root == nullptr)
			return;
		cout << root->val << ", ";
		preorder_traversal(root->left);
		preorder_traversal(root->right);
	}

private:
	bool get_path_to_leaf(node *root, node *leaf, vector <node *> &path)
	{
		if (root == nullptr)
			return false;

		if (root == leaf) {
			path.push_back(root);
			return true;
		}

		path.push_back(root);
		if (get_path_to_leaf(root->left, leaf, path))
			return true;

		if (get_path_to_leaf(root->right, leaf, path))
			return true;
		path.pop_back();
		return false;
	}
};

int main(int argc, char **argv)
{
	vector <char> preorder = {'0', '0', '0', '#', '#', '1', '#', '#', '1', '1', '#', '#', '1', '#', '#'};

	solution s;
	int idx = 0;
	node *root = s.build_tree(preorder, idx);
	s.preorder_traversal(root); cout << endl;
	int k = 3;
	node *leaf = s.get_kth_leaf(root, k);
	s.invert_leaf(root, leaf);

	s.preorder_traversal(root); cout << endl;
}
