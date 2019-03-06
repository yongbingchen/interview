#include <iostream>
#include <vector>

using namespace std;

struct node {
	string key;
	vector <node *>next;
	node(string x) : key(x), next(26, nullptr)
	{}
};

class trie_tree {
	public:
		node *build_tree(vector <string> &dict)
		{
			node *root = new node("");
			for (auto &w : dict)
				tree_insert(root, w);
			return root;
		}

		void sort(node *root, vector <string> &result)
		{
			if (root == nullptr)
				return;
			node *p = root;
			if (!p->key.empty()) {
				result.push_back(p->key); //! do not return here, will miss lexicographically after lexicographic
			}

			for (auto &i : p->next)
				sort(i, result);
		}

	private:
		void tree_insert(node *root, string word)
		{
			node *p = root;
			for (auto &c :  word) {
				if (p->next[c- 'a'] == nullptr) {
					p->next[c-'a'] = new node("");
				}
				p = p->next[c - 'a'];
			}

			p->key = word;
		}

};

int main(int argc, char **argv)
{
	vector <string> dict = {
		"lexicographic", "sorting", "of", "a", "set", "of", "keys", "can",
		"be", "accomplished", "with", "a", "simple", "trie", "based",
		"algorithm", "we", "insert", "all", "keys", "in", "a", "trie",
		"output", "all", "keys", "in", "the", "trie", "by", "means", "of",
		"preorder", "traversal", "which", "results", "in", "output", "that",
		"is", "in", "lexicographically", "increasing", "order", "preorder",
		"traversal", "is", "a", "kind", "of", "depth", "first", "traversal"
	};

	trie_tree s;
	node *root = s.build_tree(dict);
	vector <string> result;
	s.sort(root, result);
	for (auto &i : result)
		cout << i << endl;
	exit(EXIT_SUCCESS);
}
