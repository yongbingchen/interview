#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct tree_node {
	int val;
	tree_node *left;
	tree_node *right;
	tree_node(int x) : val(x), left(nullptr), right(nullptr)
	{}
};

class tree_builder {
public:
	tree_node *build_tree(const vector <int> preorder, const vector <int>
			inorder)
	{
		tree_node *root;

		root = build_tree(preorder.begin(), preorder.end(),
				inorder.begin(), inorder.end());
		return root;
	}

	vector <int> inorder_traversal(const tree_node *root)
	{
		vector <int> result;
		inorder_traversal(root, result);
		return result;
	}
	vector <int> preorder_traversal(const tree_node *root)
	{
		vector <int> result;
		preorder_traversal(root, result);
		return result;
	}

private:
	template <typename my_iterator>
	tree_node *build_tree(my_iterator preorder_first,
			my_iterator preorder_end,
			my_iterator inorder_first,
			my_iterator inorder_end)
	{
		tree_node *root;

		if (preorder_first == preorder_end)
			return nullptr;

		if (inorder_first == inorder_end)
			return nullptr;

		root = new tree_node(*preorder_first);
		my_iterator root_in_inorder =
			find(inorder_first, inorder_end, *preorder_first);
		int left_tree_size =
			distance(inorder_first, root_in_inorder);
		/* next(it) is the same as advance(it, 1);*/
		/* 'end' iterator need to point to the one not belongs to the set,*/
		/* thus the '+1'.*/
		my_iterator left_tree_end =
			next(preorder_first, left_tree_size + 1);

		root->left = build_tree(next(preorder_first),
				left_tree_end,
				inorder_first,
				root_in_inorder);

		root->right = build_tree(left_tree_end,
				preorder_end,
				next(root_in_inorder),
				inorder_end);
		return root;
	}

	void inorder_traversal(const tree_node *root, vector <int> &result)
	{
		if (root == nullptr)
			return;

		inorder_traversal(root->left, result);
		result.push_back(root->val);
		inorder_traversal(root->right, result);
	}

	void preorder_traversal(const tree_node *root, vector <int> &result)
	{
		if (root == nullptr)
			return;

		result.push_back(root->val);
		preorder_traversal(root->left, result);
		preorder_traversal(root->right, result);
	}

};

class solution {
public:
	int sum_nums(const tree_node *root)
	{
		return sum_nums(root, 0);
	}
private:
	int sum_nums(const tree_node *root, int sum)
	{
		if (root == nullptr)
			return sum;
		sum = sum * 10 + root->val;
		if (root->left == nullptr && root->right == nullptr)
			return sum;

		int left = sum_nums(root->left, sum);
		int right = sum_nums(root->right, sum);

		//not sum + left + right, because sum is not a leaf node.
		return left + right;
	}

};

int main(int argc, char **argv)
{
	const vector <int> inorder = {8, 4, 2, 5, 9, 1, 6, 3, 7, 10};
	const vector <int> preorder = {1, 2, 4, 8, 5, 9, 3, 6, 7, 10};

	tree_builder b;

	tree_node *root = b.build_tree(preorder, inorder);

	vector <int> in = b.inorder_traversal(root);
	cout << "inorder traversal of the tree:" << endl;
	for (const auto &i : in)
		cout << i;
	cout << endl;

	vector <int> pre = b.preorder_traversal(root);
	cout << "preorder traversal of the tree:" << endl;
	for (const auto &i : pre)
		cout << i;
	cout << endl;

	solution a;

	cout << "total sum of the tree " << a.sum_nums(root) << endl;

	exit(EXIT_SUCCESS);
}

