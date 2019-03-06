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
		vector <vector <int>> get_path_with_sum(const tree_node *root, const int sum)
		{
			vector <vector <int>> result;
			vector <int> path;

			dfs(root, sum, 0, path, result);
			return result;
		}
	private:
		void dfs(const tree_node *root, const int sum, int curr, vector <int> &path, vector <vector <int>> &result)
		{
			if (root == nullptr)
				return;

			path.push_back(root->val);
			if (root->left == nullptr && root->right == nullptr) {
				if (curr + root->val == sum)
					result.push_back(path);
				path.pop_back();
				return;
			}

			dfs(root->left, sum, curr + root->val, path, result);
			dfs(root->right, sum, curr + root->val, path, result);
			path.pop_back(); //backtracking
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
	vector <vector <int>> ret;
	ret = b.get_path_with_sum(root, 11);

	for (const auto &v : ret) {
		cout << "get a path with sum 11:" << endl;
		for (const auto &j : v)
			cout << j;
		cout << endl;
	}
}
