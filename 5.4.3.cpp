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

class tree_builder {
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

class solution {
	public:
		bool is_path_sum_exist(const tree_node *root, const int sum)
		{
			if (root == nullptr || sum < 0)
				return false;

			//my error, leaf node is a special case.
			if (root->left == nullptr && root->right == nullptr)
				return sum == root->val;

			if (is_path_sum_exist(root->left, sum - root->val))
				return true;

			if (is_path_sum_exist(root->right, sum - root->val))
				return true;

			return false;
		}
};

int main(int argc, char **argv)
{
	tree_builder a;
	const vector <int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	tree_node *root = a.sorted_array_to_bst(array);

	vector <int> result = a.inorder_traversal(root);
	for (const auto &i : result)
		cout << i;
	cout << endl;

	solution b;
	vector <int> sum = {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
	for (const auto & i : sum) {
		cout << "is tree has path with sum " << i << " true ? "
			<< b.is_path_sum_exist(root, i) << endl;
	}
}
