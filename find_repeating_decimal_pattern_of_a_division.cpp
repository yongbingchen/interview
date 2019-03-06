#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution {
	public:
		string find_pattern(int m, int n)
		{
			string division; //"714285714285714285"; result of 7 / 5 = 0.714285714285
			int r = m;
			for (int i = 0; i < n * 2; i++) {
				int bit = r * 10 / n;
				r = (r * 10) % n;
				division += to_string(bit);
			}

			for (int i = n - 1; i > 0; i--) { //based on number theory, the maxium repeating len is 'n - 1'
				string pattern = division.substr(0, i);
				if (is_match(division, pattern))
					return pattern;
			}
			return "";
		}
	private:
		bool is_match(string s, string pattern)
		{
			if (s.substr(pattern.size()).find(pattern) != string::npos)
				return true;

			return false;
		}
};

int main(int argc, char **argv)
{
	int m = 5;
	int n = 7;
	solution s;
	string pattern = s.find_pattern(m, n);
	cout << pattern << endl;
}
