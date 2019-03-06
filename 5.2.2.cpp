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

class solution {
	public:
		tree_node *build_tree(const vector <int> postorder, const vector <int> inorder)
		{
			tree_node *result;

			result = build_tree(postorder.begin(),
					postorder.end(),
					inorder.begin(),
					inorder.end());

			return result;
		}

		vector <int> inorder_traversal(const tree_node *root)
		{
			vector <int> result;

			inorder_traversal(root, result);

			return result;
		}

	private:
		//CAUTION! this template typename can not in 'public:' section
		template <typename order_iterator>
		tree_node *build_tree(order_iterator post_first,
				order_iterator post_last,
				order_iterator in_first,
				order_iterator in_last)
		{
			if (post_first == post_last)
				return nullptr;

			if (in_first == in_last)
				return nullptr;

			tree_node *root = new tree_node(*prev(post_last));

			//CAUTION! vector.end() is a nullptr, not a real element.
			//while vector.front() is a real element's iterator.
			order_iterator root_in_pos = find(in_first, in_last, *prev(post_last));
			int left_tree_size = distance(in_first, root_in_pos);
			order_iterator post_last_left = next(post_first, left_tree_size);

			cout << "curr root node " << *prev(post_last) << ", left tree size is " << left_tree_size << endl;

			// left tree's post_last == right tree's post first.
			// because of the vector.end() meaning (not the real elment, but a nullptr)
			root->left = build_tree(post_first,
					post_last_left, //point to the right tree's post_first, but used as left's post last.
					in_first,
					root_in_pos);

			root->right = build_tree(post_last_left,
					prev(post_last), //move ahead of the current root.
					next(root_in_pos),
					in_last);

			return root;
		}

		void inorder_traversal(const tree_node *root,
				vector <int> &result)
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
	/*		       1
	 *		      /  \
	 *		     2     3
	 *		    / \   / \
	 *                 4   5 6   7
	 * */
	const vector <int> inorder = {4, 2, 5, 1, 6, 3, 7};
	const vector <int> postorder = {4, 5, 2, 6, 7, 3, 1};

	solution a;
	tree_node *root = a.build_tree(postorder, inorder);

	vector <int> result = a.inorder_traversal(root);

	for (const auto & i : result)
		cout << i;
	cout << endl;
}
