#include <iostream>
#include <string>
#include <vector>

using namespace std;

class solution {
	public:
		string get_lcs(string a, string b, int len_a, int len_b)
		{
			if (len_a == 0 || len_b == 0)
				return string("");

			if (a[len_a - 1] == b[len_b - 1])
				return get_lcs(a, b, len_a - 1, len_b - 1) + a[len_a - 1];

			if (lcs_table[len_a][len_b - 1] >  lcs_table[len_a - 1][len_b])
				return get_lcs(a, b, len_a, len_b - 1);
			else
				return get_lcs(a, b, len_a - 1, len_b);
		}
		void fill_lcs_table(string a, string b, int len_a, int len_b)
		{
			lcs_table.assign(len_a + 1, vector <int>(len_b + 1, 0));
			for (int len_i = 1; len_i < len_a + 1; len_i++) {
				for (int len_j = 1; len_j < len_b + 1; len_j++) {
					if (a[len_i - 1] == b[len_j - 1]) {
						lcs_table[len_i][len_j] = lcs_table[len_i - 1][len_j - 1] + 1;
					}
					else {
						lcs_table[len_i][len_j] = max(lcs_table[len_i - 1][len_j], lcs_table[len_i][len_j - 1]);
					}
				}
			}

		}
	private:
		vector <vector <int>> lcs_table;
};

int main(int argc, char **argv)
{
	string a = "XMJYAUZ", b = "MZJAWXU";
	solution s;

	s.fill_lcs_table(a, b, a.size(), b.size());
	cout << "search lcs of " << a << " and " << b << endl;
	string ret = s.get_lcs(a, b, a.size(), b.size());
	cout << "lcs of " << a << " and " << b << " is " << ret << endl;

	exit(EXIT_SUCCESS);
}
