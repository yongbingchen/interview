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
		vector <tree_node *> build_bst(const int node_num)
		{
			return build_bst(1, node_num);
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


	private:
		vector <tree_node *> build_bst(const int start_num, const int end_num)
		{
			vector <tree_node *> result;

			if (start_num > end_num) {
				result.push_back(nullptr);
				return result;
			}

			for (int k = start_num; k <= end_num; k++) {
				vector <tree_node *> left_subs = build_bst(start_num, k - 1);
				vector <tree_node *> right_subs = build_bst(k + 1, end_num);

				for (auto &i : left_subs) {
					for (auto &j : right_subs) {
						tree_node *root = new tree_node(k);
						root->left = i;
						root->right = j;
						result.push_back(root);
					}
				}
			}

			return result;
		}
};

int main(int argc, char **argv)
{
	int num = stoi(argv[1]);
	solution a;

	vector <tree_node *>result;
	result = a.build_bst(num);

	int total_bsts = 0;
	for (const auto &i : result) {
		vector <int> t;
		fill(t.begin(), t.end(), 0);
		a.inorder_traversal(i, t);
		cout << "get one bst from num " << num << ", total bsts " << ++total_bsts << endl;
		for (const auto &j : t)
			cout << j;
		cout << endl;

		vector <int> k;
		fill(k.begin(), k.end(), 0);
		a.preorder_traversal(i, k);
		cout << "its preorder traversal is:" << endl;
		for (const auto &j : k)
			cout << j;
		cout << endl;

	}
}
