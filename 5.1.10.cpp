#include <iostream>
#include <string>
#include <vector>
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
		bool is_balanced(const tree_node *root)
		{
			int height = 0;

			height = tree_height(root);

			return height >= 0;
		}

		void build_tree(tree_node *root, const string &preorder, int &index)
		{
			if (preorder[index] == '#')
				return;

			index++;
			root->left = new tree_node(preorder[index]);
			build_tree(root->left, preorder, index);
			index++;
			root->right = new tree_node(preorder[index]);
			build_tree(root->right, preorder, index);
		}

	private:
		int tree_height(const tree_node *root)
		{
			if (!root)
				return 0;

			int left = tree_height(root->left);
			int right = tree_height(root->right);

			if (abs(left - right) > 1)
				return -1;

			if (left < 0 || right < 0)
				return -1;

			return max(left, right) + 1;
		}
};

int main(int argc, char **argv)
{
	solution a;

	int index = 0;
	const string preorder = "123##4##5#6#78##9##";
	tree_node *root = new tree_node(preorder[index]);
	a.build_tree(root, preorder, index);

	cout << "is tree 0 a balanced tree " << a.is_balanced(root) << endl;

	index = 0;
	const string preorder2 = "123##4##5#6##";
	tree_node *t2 = new tree_node(preorder2[index]);
	a.build_tree(t2, preorder2, index);

	cout << "is tree 2 a balanced tree " << a.is_balanced(t2) << endl;
}
