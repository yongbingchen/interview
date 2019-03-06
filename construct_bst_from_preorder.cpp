#include <iostream>
#include <vector>

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
	node *build_tree(vector <int>::iterator begin, vector <int>::iterator end)
	{
		if (begin == end)
			return nullptr;

		node *root = new node(*begin);
		auto left_end = std::lower_bound(begin + 1, end, *begin);
		root->left = build_tree(begin + 1, left_end);
		root->right = build_tree(left_end, end);
		return root;
	}
	void inorder(node *root, vector <int> &order)
	{
		if (root == nullptr)
			return;
		inorder(root->left, order);
		order.push_back(root->val);
		inorder(root->right, order);
	}
};


int main(int argc, char **argv)
{
	vector <int> preorder = {10, 5, 1, 7, 40, 50};

	node *root;
	solution s;
	root = s.build_tree(preorder.begin(), preorder.end());
	vector <int> result;
	s.inorder(root, result);
	for (auto &i : result)
		cout << i << ", ";
	cout << endl;

	exit(EXIT_SUCCESS);
}
