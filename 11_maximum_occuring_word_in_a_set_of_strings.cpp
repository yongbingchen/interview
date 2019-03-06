#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct trie_node {
	string key;
	int occuring;
	vector <trie_node *> next;
	trie_node(int char_set_size)
	{
		occuring  = 0;
		next.assign(char_set_size, nullptr);
	}
};

class trie {
	public:
		void insert(trie_node *h, string key)
		{
			if (h == nullptr)
				return;
			for (auto &ch : key) {
				if (h->next[ch - 'a'] == nullptr)
					h->next[ch - 'a'] = new trie_node(26);
				h = h->next[ch - 'a'];
			}
			h->key = key;
			h->occuring += 1;
		}

		void preorder(trie_node *h, int &max_occuring, string &max_word)
		{
			if (h == nullptr)
				return;

			if (h->occuring > max_occuring) {
				max_occuring = h->occuring;
				max_word = h->key;
			}

			for (auto &i : h->next) {
				if (i != nullptr)
					preorder(i, max_occuring, max_word);
			}
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

	trie_node *h = new trie_node(26);
	trie t;
	for (auto &i : dict)
		t.insert(h, i);

	int max_occuring = 0;
	string max_word;
	t.preorder(h, max_occuring, max_word);
	cout << "word " << max_word << " occured " << max_occuring << " times, it's the maximum occuring word" << endl;

	exit(EXIT_SUCCESS);
}
