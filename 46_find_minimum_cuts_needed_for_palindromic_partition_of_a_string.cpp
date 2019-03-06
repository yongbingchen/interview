#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class solution {
	public:
		int min_cuts(string s, int start, int end)
		{
			if (start == end)
				return 0;
			if (is_palindrom(s, start, end))
				return 0;

			int min_c = INT_MAX;
			for (int i = start; i < end; i++) {
				int cuts = min_cuts(s, start, i) + min_cuts(s, i + 1, end);
				min_c = min(cuts + 1, min_c);
			}

			return min_c;
		}
	private:
		bool is_palindrom(string s, int start, int end)
		{
			while(start != end) {
				if (s[start++] != s[end--])
					return false;
			}
			return true;
		}
};

int main(int argc, char **argv)
{
	vector <string> test = {
		"BABABCBADCD",
		"ABCBA",
		"ABCD",
	};
	solution s;

	for (auto &i : test) {
		int ret = s.min_cuts(i, 0, i.size() - 1);
		cout << i << " need minimum " << ret << " cuts to make it palindrom" << endl;
	}

	exit(EXIT_SUCCESS);
}
