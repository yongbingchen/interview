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
                vector <vector <char>> level_order_traversal_recursive(const tree_node *root)
                {
                        vector <vector <char>> result;
                        int level = 1;
                        level_traversal(root, level, result);

                        return result;
                }

                vector <vector <char>> level_order_traversal_iterate(const tree_node *root)
                {
                        vector <vector <char>> result;
                        queue <const tree_node *> this_level, next_level;

                        if (root == nullptr)
                                return result;

                        this_level.push(root);

                        while(!this_level.empty()) {
                                vector <char> level_result;

                                while(!this_level.empty()) {
                                        const tree_node *p = this_level.front();
                                        this_level.pop();
                                        level_result.push_back(p->val);

                                        if (p->left)
                                                next_level.push(p->left);

                                        if (p->right)
                                                next_level.push(p->right);
                                }

                                result.push_back(level_result);
				//this level swap only needed if we want store result by level,
				//otherwise one queue is enough
                                swap(this_level, next_level);
                        }

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

        private:
                void level_traversal(const tree_node *root, const int level, vector <vector <char>> &result)
                {
                        if (!root)
                                return;

                        if (level > result.size())
                                result.push_back(vector <char>());

                        result[level - 1].push_back(root->val);

                        //CAUTION! again, can not pass constant (level + 1) as reference.
                        level_traversal(root->left, level + 1, result);
                        level_traversal(root->right, level + 1, result);
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
        result = a.level_order_traversal_recursive(root);

        int i = 0;
        for (auto v : result) {
                cout << "get result at level " << i++ << endl;
                for ( auto c : v)
                        cout << c;
                cout << endl;
        }

        vector <vector <char>> result2;
        result2 =  a.level_order_traversal_iterate(root);
        i = 0;
        for (auto v : result) {
                cout << "get result at level " << i++ << endl;
                for ( auto c : v)
                        cout << c;
                cout << endl;
        }


}
