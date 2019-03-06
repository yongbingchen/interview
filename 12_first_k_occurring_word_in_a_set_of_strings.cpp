#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define TOTAL_CHAR (26)
struct trie_node {
	string val;
	int cnt;
	vector <trie_node *> next;
	trie_node() : val(""), cnt(0), next(TOTAL_CHAR, nullptr)
	{}
};

class trie {
	public:
		void insert(trie_node *root, string word)
		{
			if (root == nullptr)
				return;
			trie_node *p = root;
			for (auto &c : word) {
				if (p->next[c - 'a'] == nullptr)
					p->next[c - 'a'] = new trie_node();

				p = p->next[c - 'a'];
			}
			if (p->val.size() == 0)
				p->val = word;
			p->cnt++;
		}

		void preorder(trie_node *p, map <int, vector <string>> &occuring)
		{
			if (p == nullptr)
				return;

			if (p->val.size() != 0)
				occuring[p->cnt].push_back(p->val);

			for (auto &q : p->next)
				preorder(q, occuring);
		}

};


int main(int argc, char **argv)
{
	vector <string> dict = {
		"code", "coder", "coding", "codable", "codec", "codecs", "coded",
		"codeless", "codec", "codecs", "codependence", "codex", "codify",
		"codependents", "codes", "code", "coder", "codesign", "codec",
		"codeveloper", "codrive", "codec", "codecs", "codiscovered"
	};

	trie_node *h = new trie_node();
	trie t;
	for (auto &i : dict)
		t.insert(h, i);

	map <int, vector <string>> occuring;
	t.preorder(h, occuring);

	for (auto it = occuring.begin(); it != occuring.end(); it++) {
		for (auto &j : it->second)
			cout << "word " << j << " occured " << it->first << " times, it's the curr minimum occuring word" << endl;
	}

	exit(EXIT_SUCCESS);
}
