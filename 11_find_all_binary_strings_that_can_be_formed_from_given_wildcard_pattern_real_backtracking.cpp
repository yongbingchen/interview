#include <iostream>
#include <vector>

using namespace std;

class solution {
public:
	void wildcard_expansion(string pattern, int idx, vector <char> &char_set, vector <string> &result)
	{
		if (idx == pattern.size()) {
			result.push_back(pattern);
			return;
		}

		if (pattern[idx] != '?')
			return wildcard_expansion(pattern, idx + 1, char_set, result);

		for (auto &c : char_set) {
			pattern[idx] = c;
			wildcard_expansion(pattern, idx + 1, char_set, result);
		}
	}
};

int main(int argc, char **argv)
{
	solution s;
	vector <string> result;
	vector <char> char_set = {'0', '1'};
	string pattern = "1?11?00?1?";
	s.wildcard_expansion(pattern, 0, char_set, result);
	for (auto &s: result)
		cout << s << endl;
	exit(EXIT_SUCCESS);
}
