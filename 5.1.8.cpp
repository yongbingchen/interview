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
		bool is_same_tree(const tree_node *t1, const tree_node *t2)
		{
			if (t1 == nullptr && t2 == nullptr)
				return true;

			if (t1 == nullptr && t2 != nullptr)
				return false;

			if (t1 != nullptr && t2 == nullptr)
				return false;

			if (t1->val != t2->val)
				return false;

			if (!is_same_tree(t1->left, t2->left))
				return false;

			if (!is_same_tree(t1->right, t2->right))
				return false;

			return true;
		}

		bool is_same_tree_iterate(const tree_node *t1, const tree_node *t2)
		{
			stack <const tree_node *> s1, s2;

			const tree_node *p1 = t1, *p2 = t2;

			s1.push(p1);
			s2.push(p2);

			while(!s1.empty() && !s2.empty()){
				p1 = s1.top();
				p2 = s2.top();

				if (p1 == nullptr && p2 != nullptr)
					return false;
				if (p1 != nullptr && p2 == nullptr)
					return false;
				if (p1 == nullptr && p2 == nullptr) {
					s1.pop();
					s2.pop();
					continue;
				}

				if (p1->val != p2->val)
					return false;

				s1.pop();
				s2.pop();
				s1.push(p1->left);
				s1.push(p1->right);
				s2.push(p2->left);
				s2.push(p2->right);
			}

			if (s1.empty() && s2.empty())
				return true;

			return false;
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
};

int main(int argc, char **argv)
{
	const string preorder = "123##4##5#6#78##9##";
	const string preorder2 = "123##4##5#6#78##a##";
	const string preorder3 = "123##4##5#6#78##9##";
	solution a;

	int index = 0;
	tree_node *t1 = new tree_node(preorder[index]);
	a.build_tree(t1, preorder, index);
	index = 0;
	tree_node *t2 = new tree_node(preorder2[index]);
	a.build_tree(t2, preorder2, index);
	index = 0;
	tree_node *t3 = new tree_node(preorder3[index]);
	a.build_tree(t3, preorder3, index);

	cout << "is same tree " << a.is_same_tree(t1, t2) << endl;
	cout << "is same tree t1 t3 " << a.is_same_tree(t1, t3) << endl;
	cout << "is same tree iterate " << a.is_same_tree_iterate(t1, t2) << endl;
	cout << "is same tree iterate t1 t3 " << a.is_same_tree_iterate(t1, t3) << endl;

}
