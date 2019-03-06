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
		vector <vector <char>> zigzag_traversal(const tree_node *root)
		{
			vector <vector <char>> result;
			queue <const tree_node *> this_level, next_level;
			const tree_node *p = root;
			int order = 0;

			if (!root)
				return result;

			this_level.push(p);

			while(!this_level.empty()) {
				vector <char> level_result;

				while(!this_level.empty()) {
					p = this_level.front();
					this_level.pop();
					level_result.push_back(p->val);

					if (p->left)
						next_level.push(p->left);

					if (p->right)
						next_level.push(p->right);
				}

				swap(this_level, next_level);

				if (order & 0x1)
					reverse(level_result.begin(), level_result.end());
				order ^= 1;

				result.push_back(level_result);
			}

			return result;
		}

		void build_tree(tree_node *root, const string &preorder_traversal, int &index)
		{
			//my error! do not use if (!root) as recursive stop condition.
			if (preorder_traversal[index] == '#')
				return;

			index++;
			root->left = new tree_node(preorder_traversal[index]);
			build_tree(root->left, preorder_traversal, index);
			index++;
			root->right = new tree_node(preorder_traversal[index]);
			build_tree(root->right, preorder_traversal, index);
		}
};

int main(int argc, char **argv)
{
	const string preorder_traversal = "123##4##5#6#78##9##";
	solution a;

	int index = 0;
	tree_node *root = new tree_node(preorder_traversal[index]);
	a.build_tree(root, preorder_traversal, index);

	vector <vector <char>> result;
	result = a.zigzag_traversal(root);

	int i = 0;
	for (const auto &b : result) {
		cout << "zigzag in level " << i << endl;
		for (const auto &c : b)
			cout << c;
		cout << endl;
	}
}
