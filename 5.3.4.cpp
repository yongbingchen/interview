#include <iostream>
#include <vector>

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
		tree_node *sorted_array_to_bst(const vector <int> &array)
		{
			return sorted_array_to_bst(array.begin(), array.end());
		}

		vector <int> inorder_traversal(const tree_node *root)
		{
			vector <int> result;
			inorder_traversal(root, result);
			return result;
		}
	private:
		template <typename list_iterator>
		tree_node *sorted_array_to_bst(list_iterator begin, list_iterator end)
		{
			const auto len = distance(begin, end);

			if (len <= 0)
				return nullptr;

			auto mid = begin + len / 2;

			tree_node *root = new tree_node(*mid);

			root->left = sorted_array_to_bst(begin, mid);
			//root->right = sorted_array_to_bst(mid + 1, end);
			//CAUTION! next(it) equals it + 1
			root->right = sorted_array_to_bst(next(mid), end);

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
	const vector <int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	tree_node *root = a.sorted_array_to_bst(array);

	vector <int> result = a.inorder_traversal(root);
	for (const auto &i : result)
		cout << i;
	cout << endl;
}
