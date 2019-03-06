#include <iostream>
#include <string>
#include <stack>
#include <vector>

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
                vector <char> postorder_traversal(tree_node *root)
		{
			vector <char> result;
			stack <tree_node *> s;
			tree_node *p = root;
			tree_node *last = nullptr;
			s.push(p);
			while(!s.empty()) {
				p = s.top();
                                p = s.top();
                                //to visit curr stack top node, must be one of these three cases:
                                //1. it's a leaf.
                                //2. or its right child does not exit, and its left child just be visited.
                                //3. or its right child just be visited.
				if (p->left == nullptr && p->right == nullptr ||
						p->right == nullptr && last == p->left ||
						last == p->right) {
					result.push_back(p->val);
					s.pop();
					last = p;
				}
				else {
					if (p->right != nullptr)
						s.push(p->right);
					if (p->left != nullptr)
						s.push(p->left);
				}
			}

			return result;
		}

                void postorder_traversal_recursive(const tree_node *root, vector <char> &result)
                {
                        if (root == nullptr)
                                return;

                        postorder_traversal_recursive(root->left, result);
                        postorder_traversal_recursive(root->right, result);
                        result.push_back(root->val);
                }

                void build_tree(tree_node *root, const string &preorder_traversal, int &index)
                {
                        //WRONG!if (root->val == '#')
                        if (preorder_traversal[index] == '#')
                                return;

                        index++;
                        root->left = new tree_node(preorder_traversal[index]);
                        //CAUTION!, use below method will lose all leaf node (with value '#')
                        //root->left = build_tree(root->left, preorder_traversal, ++index);
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

        vector <char> result2;
        a.postorder_traversal_recursive(root, result2);
        for (const auto &c : result2)
                cout << c;
        cout << endl;

        vector <char> result = a.postorder_traversal(root);
        for (const auto &c : result)
                cout << c;
        cout << endl;
}
