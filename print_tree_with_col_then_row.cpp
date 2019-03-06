#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct node {
	int val;
	node *left;
	node *right;
	int row;
	int col;
	node(int x) : val(x), right(nullptr), left(nullptr), row(-1), col(-1)
	{}
};

class solution {
public:
	void print_tree(node *root)
	{
		set_row_col(root, 0, 0);

		int row = INT_MIN, right = INT_MIN, left = INT_MAX, col = 0;
		get_max_row_and_col(root, row, left, right);
		if (left != INT_MAX)
			col += abs(left);
		if (right != INT_MIN)
			col += right;
		cout << "max row " << row << ", max_col " << col << endl;

		vector <vector <int>> result(row + 1, vector <int>(col + 1, -1));
		map_node_to_matrix(root, abs(left), result);

		//print out the result, by col/row order
		for (int j = 0; j < result[0].size(); j++) {
			for (int i = 0; i < result.size(); i++)
				if (result[i][j] != -1)
					cout << result[i][j] << ", ";
		}
		cout << endl;
	}

private:
	void get_max_row_and_col(node *root, int &row, int &left, int &right)
	{
		if (root == nullptr)
			return;
		row = max(row, root->row);
		left = min(left, root->col);
		right = max(right, root->col);
		get_max_row_and_col(root->left, row, left, right);
		get_max_row_and_col(root->right, row, left, right);
	}

	void set_row_col(node *root, int level, int col)
	{
		if (root == nullptr)
			return;

		root->row = level;
		root->col = col;
		if (root->left)
			set_row_col(root->left, level + 1, col - 1);

		if (root->right)
			set_row_col(root->right, level + 1, col + 1);

	}

	void map_node_to_matrix(node *root, int left, vector <vector <int>> &result)
	{
		if (root == nullptr)
			return;
		result[root->row][root->col + left] = root->val;
		map_node_to_matrix(root->left, left, result);
		map_node_to_matrix(root->right, left, result);
	}
};

class tree {
public:
	node *build_tree(vector <int> &inorder, vector <int> &preorder)
	{
		return build_tree(inorder.begin(), inorder.end(), preorder.begin(), preorder.end());
	}
	void traversal(node *root)
	{
		if (root == nullptr)
			return;
		cout << root->val << ", ";
		traversal(root->left);
		traversal(root->right);
	}
private:
	template <typename iterator>
	node *build_tree(iterator i_begin, iterator i_end, iterator p_begin, iterator p_end)
	{
		if (p_begin == p_end)
			return nullptr;

		node *root = new node(*p_begin);
		auto root_in_inorder = find(i_begin, i_end, *p_begin);
		size_t left_size = distance(i_begin, root_in_inorder);
		iterator p_left_end = next(p_begin) + left_size;

		root->left = build_tree(i_begin, root_in_inorder, next(p_begin), p_left_end);
		root->right = build_tree(next(root_in_inorder), i_end, p_left_end, p_end);

		return root;
	}
};

int main(int argc, char **argv)
{
	vector <int> preorder = {6, 9, 5, 0, 1, 4, 3, 7};
	vector <int> inorder = {5, 0, 9, 1, 6, 4, 7, 3};

	tree t;
	node *root = t.build_tree(inorder, preorder);
	t.traversal(root); cout << endl;
	solution s;
	s.print_tree(root);
}
