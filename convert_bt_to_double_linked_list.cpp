#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct node {
	int val;
	node *left;
	node *right;
	node(int x) : val(x), left(nullptr), right(nullptr)
	{}
};

class solution {
public:
	node *build_tree(vector <int> &preorder, vector <int> &inorder)
	{
		return build_tree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
	}

	node *convert(node *root)
	{
		if (root == nullptr)
			return nullptr;
		node *head = nullptr;
		stack <node *> s;

		node *p = root;
		node *prev = nullptr;
		node *tail = nullptr;
		while(!s.empty() || p != nullptr) {
			if (p != nullptr) {
				s.push(p);
				p = p->left;
			}
			else {
				p = s.top();
				s.pop();

				if (prev == nullptr) {
					head = prev = p;
					p->left = nullptr;
				}
				else {
					p->left = prev; //at this point the left child must already visited, so safe to overwrite the pointer.
					prev->right = p;
					prev = p;
				}
				tail = p;

				//below part equals to p = p->right, write like this for easier reading.
				if (p->right != nullptr)
					p = p->right;
				else
					p = nullptr;
			}
		}

		tail->right = nullptr;
		return head;
	}

private:
	template <typename iterator>
	node *build_tree(iterator p_begin, iterator p_end, iterator i_begin, iterator i_end)
	{
		if (p_begin == p_end)
			return nullptr;

		node *root = new node(*p_begin);
		iterator root_in_inorder = find(i_begin, i_end, *p_begin);
		size_t left_size = distance(i_begin, root_in_inorder); //distance of a[0] and a[3] is 3
		iterator left_end = next(i_begin + left_size);

		root->left = build_tree(next(p_begin),
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
	vector <int> preorder = {10, 12, 25, 30, 15, 36};
	vector <int> inorder = {25, 12, 30, 10, 36, 15};

	solution s;
	node *root = s.build_tree(preorder, inorder);
	node *head = s.convert(root);

	node *p = head;
	node *prev = nullptr;
	while(p != nullptr) {
		cout << p->val << ", ";
		prev = p;
		p = p->right;
	}
	cout <<endl;
	p = prev;
	while(p != nullptr) {
		cout << p->val << ", ";
		p = p->left;
	}
	cout <<endl;
}
