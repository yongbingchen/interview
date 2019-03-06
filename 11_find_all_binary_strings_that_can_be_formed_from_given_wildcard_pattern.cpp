#include <iostream>
#include <string>
#include <vector>

using namespace std;

class solution {
	public:
		void wildcard_expansion(string pattern, int n, vector <string> &result)
		{
			if (n == pattern.size())
				return;

			if (pattern[n] != '?') {
				for (auto &s : result)
					s += pattern[n];
			}
			else {
				//!WRONG, can not do iterating while change the container size itself
				//for (auto &s : result) {
				int n = result.size();
				for (int i = 0; i < n; i++) {
					string t = result[i];
					result[i] += '0';
					t += '1';
					result.push_back(t);
				}
			}
			wildcard_expansion(pattern, n + 1, result);
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <string> result(1);
	string pattern = "1?11?00?1?";
	s.wildcard_expansion(pattern, 0, result);
	for (auto &s: result)
		cout << s << endl;
	exit(EXIT_SUCCESS);
}
