#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct node {
	int val;
	node *left;
	node *right;
	node(int x) : val(x), left(nullptr), right(nullptr)
	{}
};


class solution {
	public:
		node *build_tree(vector <int> &preorder, vector <int> &inorder)
		{
			return build_tree(preorder.begin(), preorder.size(), inorder.begin(), inorder.size());

		}

		void inorder(node *root, vector <int> &result)
		{
			if (root == nullptr)
				return;
			inorder(root->left, result);
			result.push_back(root->val);
			inorder(root->right, result);
		}

	private:
		node *build_tree(vector <int>::iterator preorder, int p_size, vector <int>::iterator inorder, int i_size)
		{
			if (p_size == 0)
				return nullptr;

			node *root = new node(*preorder);

			auto it = find(inorder, inorder + i_size, *preorder);
			auto left_size = distance(inorder, it);
			root->left = build_tree(next(preorder),
					left_size,
					inorder,
					left_size);
			root->right = build_tree(next(preorder + left_size),
					p_size - left_size - 1,
					next(it),
					i_size - left_size - 1);
			return root;
		}
};

int main(int argc, char **argv)
{
	/*		       1
	 *		      /  \
	 *		     2     3
	 *		    / \   / \
	 *                 4   5 6   7
	 * */
	vector <int> preorder = {1, 2, 4, 5, 3, 6, 7};
	vector <int> inorder = {4, 2, 5, 1, 6, 3, 7};

	solution a;
	node *root = a.build_tree(preorder, inorder);

	vector <int> result;
	a.inorder(root, result);
	for (const auto & i : result)
		cout << i;
	cout << endl;
}
