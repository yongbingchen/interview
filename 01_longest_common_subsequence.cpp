#include <iostream>
#include <string>
#include <vector>

using namespace std;

//https://www.techiedelight.com/longest-common-subsequence/
class solution {
	public:
		int lcs(string a, string b, int a_len, int b_len)
		{
			if (a_len == 0 || b_len == 0)
				return 0;

			//try to reduce the scale of the problem, case 1, they both end with same char.
			if (a[a_len - 1] == b[b_len - 1])
				return lcs(a, b, a_len - 1, b_len - 1) + 1;

			//case 2, if they are different at last char, then the lcs must be in below 2 cases:
			//2.1 string a and (string b minus last char), or
			//2.2 (string a - minus last char) and string b.
			return max(lcs(a, b, a_len, b_len - 1), lcs(a, b, a_len - 1, b_len));
		}

		int lcs_bottom_up(string a, string b, int len_a, int len_b)
		{
			if (len_a == 0 || len_b == 0)
				return 0;

			int max_lcs = 0;
			vector <vector <int>> lcs_table(len_a + 1, vector <int>(len_b + 1, 0));
			for (int len_i = 1; len_i < len_a + 1; len_i++) {
				for (int len_j = 1; len_j < len_b + 1; len_j++) {
					if (a[len_i - 1] == b[len_j - 1]) {
						lcs_table[len_i][len_j] = lcs_table[len_i - 1][len_j - 1] + 1;
					}
					else {
						lcs_table[len_i][len_j] = max(lcs_table[len_i - 1][len_j], lcs_table[len_i][len_j - 1]); //don't forget this part!
					}
					max_lcs = max(max_lcs, lcs_table[len_i][len_j]);
				}
			}

			return max_lcs;
		}
};

int main(int argc, char **argv)
{
	solution s;
	string a = "ABCBDAB", b = "BDCABA";

	cout << "the length of lcs is " << s.lcs(a, b, a.size(), b.size()) << endl;
	cout << "the length of lcs is " << s.lcs_bottom_up(a, b, a.size(), b.size()) << endl;

	exit(EXIT_SUCCESS);
}
