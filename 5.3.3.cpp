#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct tree_node {
	int val;
	tree_node *left;
	tree_node *right;
	tree_node(int x) : val(x), left(nullptr), right(nullptr)
	{}
};

class solution {
	public:
		bool is_valid_bst(const tree_node *root)
		{
			return is_valid_bst(root, INT_MAX, INT_MIN);
		}
	private:
		bool is_valid_bst(const tree_node *root,
				const int upper,
				const int lower)
		{
			if (root == nullptr)
				return true;

			if (root->val > upper || root->val < lower)
				return false;

			if (!is_valid_bst(root->left, root->val, lower))
				return false;

			if (!is_valid_bst(root->right, upper, root->val))
				return false;

			return true;
		}
};


class tree_builder {
	public:
		tree_node *build_tree(const vector <int> &preorder, const vector <int> inorder)
		{
			tree_node *result;

			result = build_tree_priv(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());

			return result;
		}
		vector <int> inorder_traversal(const tree_node *root)
		{
			vector <int> result;

			inorder_traversal(root, result);

			return result;
		}
	private:
		//this defined a template 'typename' (equal as keyword 'class' in this situation) 'input_iterator',
		//compiler will generate real function as caller passes a call with real type,
		//in that time, the template typename 'input_iterator' will be replaced with this real type,
		//which is 'vector <int>::iterator'.
		template <typename input_iterator>
		tree_node *build_tree_priv(input_iterator pre_first, input_iterator pre_last, input_iterator in_first, input_iterator in_last)
		{
			if (pre_first == pre_last)
				return nullptr;

			if (in_first == in_last)
				return nullptr;

			cout << "add node " << *pre_first << endl;
			tree_node *root = new tree_node(*pre_first);

			input_iterator root_inorder_pos =
				find(in_first, in_last, *pre_first);
			cout << "root_inorder_pos " << *root_inorder_pos << endl;
			int left_subtree_size =
				distance(in_first, root_inorder_pos);
			cout << "left_subtree_size " << left_subtree_size << endl;
			input_iterator pre_left_last = next(pre_first, left_subtree_size + 1);

			// CAUTION! next(pre_first, left_subtree_size + 1) and
			// next(pre_first + left_subtree_size + 1) are not the same:
			// because left_subtree_size returned by distance() is an integer,
			// not an iterator, as prefirst.
			root->left =
				build_tree_priv(next(pre_first),
						pre_left_last,
						in_first,
						root_inorder_pos);

			root->right =
				build_tree_priv(pre_left_last,
						pre_last,
						next(root_inorder_pos),
						in_last);

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
};

int main(int argc, char **argv)
{
	solution a;
	tree_builder b;


	/*		       4
	 *		      /  \
	 *		     2     6
	 *		    / \   / \
	 *                 1   3 5   7
	 * */
	const vector <int> preorder = {4, 2, 1, 3, 6, 5, 7};
	const vector <int> inorder = {1, 2, 3, 4, 5, 6, 7};

	tree_node *root = b.build_tree(preorder, inorder);

	vector <int> result = b.inorder_traversal(root);
	for (const auto & i : result)
		cout << i;
	cout << endl;

	cout << "is a valid bst " << a.is_valid_bst(root) << endl;

}
