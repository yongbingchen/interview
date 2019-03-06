#include <iostream>
#include <string>
#include <vector>

using namespace std;

class solution {
	public:
		bool wildcard_match(string s, string p, int idx_s, int idx_p)
		{
			if (idx_p == p.size() && idx_s == s.size())
				return true;
			if (idx_s == s.size())
				return false;

			switch (p[idx_p]) {
				case '?':
					return wildcard_match(s, p, idx_s + 1, idx_p + 1);
				case '*':
					return wildcard_match(s, p, idx_s + 1, idx_p + 1) ||
						wildcard_match(s, p, idx_s + 1, idx_p);
				default:
					return s[idx_s] == p[idx_p] &&
						wildcard_match(s, p, idx_s + 1, idx_p + 1);
			}
		}
};

int main(int argc, char **argv)
{
	solution s;
	string input = "xyzzxy";
	vector <string> pattern = {"x***y", "x***x", "x***x?", "*", "*?*", "*?"};

	for (auto &i : pattern) {
		cout << "input " << input << ", pattern " << i << ", is matching? " << s.wildcard_match(input, i, 0, 0) << endl;
	}

	exit(EXIT_SUCCESS);
}
