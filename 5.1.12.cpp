#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct tree_node {
	char val;
	tree_node *left;
	tree_node *right;
	tree_node *next;
	tree_node(char x) : val(x), left(nullptr), right(nullptr), next(nullptr)
	{}
};

class solution {
	public:
		void populate_next_pointer(tree_node *root)
		{
			tree_node dummy_head('$');
			tree_node *this_level, *next_level;

			this_level = root;

			while(this_level != nullptr) {
				next_level = &dummy_head;
				while(this_level != nullptr) {
					if (this_level->left) {
						next_level->next = this_level->left;
						next_level = next_level->next;
					}
					if (this_level->right) {
						next_level->next = this_level->right;
						next_level = next_level->next;
					}

					this_level = this_level->next;
				}
				this_level = dummy_head.next;
				//CAUTION! clear this tmp pointer, otherwise loop will not stop
				dummy_head.next = nullptr;
			}
		}

		void connect_5_4_6_recursive(tree_node *root)
		{
			connect(root, nullptr);
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

		void preorder_traversal(const tree_node *root)
		{
			if (root == nullptr)
				return;

			cout << "node val " << root->val;
			if (root->next)
		        	cout << ", node next val " << root->next->val << endl;
			else
				cout << ", without next node " << endl;

			preorder_traversal(root->left);
			preorder_traversal(root->right);
		}

		void level_traversal(const tree_node *root)
		{
			const tree_node *p;
			int level = 0;
			//CAUTION! CAN NOT USE THIS AS A VARIABLE NAME IN C++
			//queue <const tree_node *> this, next;
			queue <const tree_node *> curr, next;

			if (root == nullptr)
				return;

			curr.push(root);

			while(!curr.empty()) {
				while(!curr.empty()) {
					p = curr.front();
					curr.pop();

					if (p->left)
						next.push(p->left);
					if (p->right)
						next.push(p->right);

					cout << "at level "<< level <<" node val " << p->val;
					if (p->next)
						cout << ", node next val " << p->next->val << endl;
					else
						cout << ", without next node " << endl;
				}
				level++;
				swap(curr, next);
			}
		}
	private:
		tree_node *connect(tree_node *root, tree_node *sibling)
		{
			if (root == nullptr)
				return nullptr;

			root->next = sibling;

			//this only works for perfect binary tree:
			//all leaves are at same level,
			//all parents have two children.
			connect(root->left, root->right);

			if (sibling != nullptr)
				connect(root->right, sibling->left);
			else
				connect(root->right, nullptr);
		}
};

int main(int argc, char **argv)
{
	solution a;
	int index = 0;
	const string preorder = "123##4##5#6#78##9##";
	tree_node *root = new tree_node(preorder[index]);
	a.build_tree(root, preorder, index);

	a.populate_next_pointer(root);

	a.preorder_traversal(root);
	a.level_traversal(root);

	index = 0;
	tree_node *t2 = new tree_node(preorder[index]);
	a.build_tree(t2, preorder, index);

	a.connect_5_4_6_recursive(t2);

	cout << "try recursive way:" << endl;
	a.level_traversal(t2);

	index = 0;
	const string perfect_preorder = "123##4##56##7##";
	tree_node *t3 = new tree_node(perfect_preorder[index]);
	a.build_tree(t3, perfect_preorder, index);

	a.connect_5_4_6_recursive(t3);

	cout << "try recursive way on a perfect binary tree:" << endl;
	a.level_traversal(t3);

}
