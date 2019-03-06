#include <iostream>
#include <string>
#include <vector>
#include <stack>

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
#if 0
		//this way only get the most right nodes as output
		//15679#
		tree_node *flatten_binary_tree_wrong(tree_node *root)
		{
			if (root == nullptr)
				return nullptr;

			tree_node dummy_head('$');
			tree_node *p = &dummy_head;

			flatten_tree_priv(root, p);

			return dummy_head.right;
		}
#endif
		void flatten_tree(tree_node *root)
		{
			if (root == nullptr)
				return;

			tree_node *p, *prev = nullptr;
			stack <tree_node *> s;

			s.push(root);

			while(!s.empty()) {
				p = s.top();
				s.pop();

				if (p->right)
					s.push(p->right);
				if (p->left)
					s.push(p->left);

				if (prev != nullptr) {
					prev->right = p;
					prev->left = nullptr;
				}

				prev = p;
			}
			p->right = nullptr;
		}

		void flatten(tree_node *root)
		{
			flatten(root, nullptr);
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
		tree_node *flatten(tree_node *root, tree_node *tail)
		{
			if (root == nullptr)
				return tail;

			//IMPORTANT! double recursive!
			//1. result list's next (root->right) is its left child tree's flatten result.
			//2. the left child tree's flattened result list's tail node should be root's right child tree's flatten result list head;
			//3. the right child tree's flattened result list's tail is the final list's tail.
			root->right =
				flatten(root->left, flatten(root->right, tail));
			root->left = nullptr;
			return root;
		}
#if 0
		void flatten_tree_priv(tree_node *root, tree_node *head)
		{
			if (root == nullptr)
				return;

			head->next = root;
			flatten_tree_priv(root->left, head->next);
			flatten_tree_priv(root->right, head->next);
		}
#endif
};

int main(int argc, char **argv)
{
	solution a;
	const string preorder = "123##4##5#6#78##9##";

	int index = 0;
	tree_node *root = new tree_node(preorder[index]);
	a.build_tree(root, preorder, index);

	a.flatten(root);
	while (root != nullptr) {
		cout << root->val;
		root = root->right;
	}
	cout << endl;

	index = 0;
	tree_node *t2 = new tree_node(preorder[index]);
	a.build_tree(t2, preorder, index);

	a.flatten_tree(t2);
	while (t2 != nullptr) {
		cout << t2->val;
		t2 = t2->right;
	}
	cout << endl;

}
