#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct node {
	char val;
	node *right;
	node *down;
	node(char x) : val(x), right(nullptr), down(nullptr)
	{}
};

class solution {
public:
	node *build_tree(vector <char> &preorder, vector <char> &inorder)
	{
		return build_tree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
	}

	void flattern_recursive_failed(node *root, node *prev, node **tail)
	{
		if (root == nullptr)
			return;

		//this part is hard to work, since we are changing tree structure, while
		//not sure if the node been changed will shown later or not.
		//check leetcode.cpp 5.1.11
		if (*prev == nullptr) {
			*prev = root;
		}
		else {
			(*prev)->right = root;
			*prev = root;
		}
		*tail = root;

		flattern(root->down, prev, tail);
		flattern(root->right, prev, tail);
	}

	node *flattern(node *root)
	{
		stack <node *> s;
		s.push(root);

		node *p;
		node *prev = nullptr;
		node *tail;
		node *h;
		while(!s.empty()) {
			p = s.top();
			s.pop();
			if (prev == nullptr) {
				prev = p;
				h = p;
			}
			else {
				prev->right = p;
				prev = p;
			}

			tail = p;

			if (p->right != nullptr)
				s.push(p->right);

			if (p->down != nullptr)
				s.push(p->down);
		}

		tail->right = nullptr;
		return h;
	}

private:
	template <typename iterator>
	node *build_tree(iterator p_begin, iterator p_end, iterator i_begin, iterator i_end)
	{
		if (p_begin == p_end)
			return nullptr;

		node *root = new node(*p_begin);
		iterator root_in_inorder = find(i_begin, i_end, *p_begin);
		size_t left_size = distance(i_begin, root_in_inorder);
		iterator left_end = next(i_begin + left_size);

		root->down = build_tree(next(p_begin),
				next(p_begin + left_size),
				i_begin,
				left_end);

		root->right = build_tree(next(p_begin + left_size),
				p_end,
				left_end,
				i_end);
		return root;
	}
};

int main(int argc, char **argv)
{
	vector <char> preorder = {'M', 'C', 'A', 'N', 'X', 'Z', 'T', 'Y', 'D', 'L', 'E'};
	vector <char> inorder =  {'A', 'C', 'M', 'Z', 'X', 'N', 'Y', 'T', 'L', 'D', 'E'};

	solution s;
	node *root = s.build_tree(preorder, inorder);

	node *head = s.flattern(root);
	while (head != nullptr) {
		cout << head->val;
		head = head->right;
	}
	cout << endl;
}
