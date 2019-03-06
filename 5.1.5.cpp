#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct tree_node {
	char val;
	tree_node *left;
	tree_node *right;
	tree_node(char x) : val(x), left(nullptr), right(nullptr)
	{}
};

class solution {
	public:
		vector <vector <char>> level_traversal(const tree_node *root)
		{
			vector <vector <char>> result;
			queue <const tree_node *> this_level, next_level;

			if (root == nullptr)
				return result;

			const tree_node *p = root;
			this_level.push(p);

			while(!this_level.empty()) {
				vector <char> level_result;

				while(!this_level.empty()) {
					p = this_level.front();
					this_level.pop();
					level_result.push_back(p->val);

					//CAUTION! do not put nullptr in queue, will crash.
					if (p->left)
						next_level.push(p->left);
					if (p->right)
						next_level.push(p->right);
				}

				result.push_back(level_result);
				swap(this_level, next_level);
			}

			reverse(result.begin(), result.end());
			return result;
		}
		void build_tree(tree_node *root, const string &preorder_traversal, int &index)
		{
			if (preorder_traversal[index] == '#')
				return;

			index++;
			root->left = new tree_node(preorder_traversal[index]);
			build_tree(root->left, preorder_traversal, index);
			index++;
			root->right = new tree_node(preorder_traversal[index]);
			build_tree(root->right, preorder_traversal, index);
		}


		vector <vector <char>> level_traversal_recursive(const tree_node *root)
		{
			vector <vector <char>> result;

			if (!root)
				return result;

			level_traversal_priv(root, 1, result);

			reverse(result.begin(), result.end());

			//my error, forgot to wirte return sentence, no result got.
			return result;
		}

	private:
		// my error, not passing result as reference, so no middle result got.
		void level_traversal_priv(const tree_node *root, int level, vector <vector <char>> &result)
		{

			if (!root)
				return;

			if (result.size() < level)
				result.push_back(vector <char>());

			result[level - 1].push_back(root->val);

			level_traversal_priv(root->left, level + 1, result);
			level_traversal_priv(root->right, level + 1, result);
		}
};

int main(int argc, char **argv)
{
	const string preorder_traversal = "123##4##5#6#78##9##";

	int index = 0;
	tree_node *root = new tree_node(preorder_traversal[index]);

	solution a;
	a.build_tree(root, preorder_traversal, index);

	vector <vector <char>> result;
	result = a.level_traversal(root);
	int i = 0;
	for (const auto &b : result) {
		cout << "element at level " << i++ << endl;
		for (const auto &c : b)
			cout << c;
		cout << endl;
	}


	vector <vector <char>> result2;
	result2 = a.level_traversal_recursive(root);
	i = 0;
	for (const auto &b : result2) {
		cout << "recursive, element at level " << i++ << endl;
		for (const auto &c : b)
			cout << c;
		cout << endl;
	}
}
