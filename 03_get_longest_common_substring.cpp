#include <iostream>
#include <string>
#include <vector>

using namespace std;

class solution {
	public:
		string get_longest_common_substr(string a, string b, int len_a, int len_b)
		{
			vector <vector <int>> lcs(len_a + 1, vector <int>(len_b + 1, 0));

			int idx_a = 0;
			int max_len = 0;
			for (int len_i = 1; len_i < len_a + 1; len_i++) {
				for (int len_j = 1; len_j < len_b + 1; len_j++) {
					if (a[len_i - 1] == b[len_j - 1]) {
						lcs[len_i][len_j] = lcs[len_i - 1][len_j - 1] + 1;
						if (lcs[len_i][len_j] > max_len) {
							max_len = lcs[len_i][len_j];
							idx_a = len_i - 1;
						}
					}
					//compare to the common subseq case, when a[len_i - 1] != b[len_j - 1], the lcs[len_i][len_j] = 0, so can not use the same top down method as common subseq (no restriction for the sequnce to be continious in orig sequence
				}
			}
			if (max_len > 0)
				return a.substr(idx_a - (max_len - 1), max_len); //max_len - 1 to include idx_a itself, calculate the case just like move a pointer.

			return string("");
		}
};

int main(int argc, char **argv)
{
	solution s;
	string a = "BABCCBEABCDEFGBAAB", b = "BABAAB";

	string ret = s.get_longest_common_substr(a, b, a.size(), b.size());
	cout << "longest common substring of " << a << " and " << b << " is " << ret << endl;
	exit(EXIT_SUCCESS);
}
