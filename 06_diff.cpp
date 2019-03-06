#include <iostream>
#include <string>
#include <vector>

using namespace std;

class solution {
	public:
		string diff(string a, string b, int len_a, int len_b)
		{
			if (len_a == 0 && len_b == 0)
				return string("");

			if (len_b == 0)
				return "-" + a.substr(len_a - 1);

			if (len_a == 0)
				return "+" + b.substr(len_b - 1);

			if (a[len_a - 1] == b[len_b - 1])
				return diff(a, b, len_a - 1, len_b - 1) + a[len_a - 1];

			if (lcs[len_a - 1][len_b] > lcs[len_a][len_b - 1])
				return diff(a, b, len_a - 1, len_b) + "-" + a[len_a - 1];
			else
				return diff(a, b, len_a, len_b - 1) + "+" + b[len_b - 1];
		}

		void fill_lcs_table(string a, string b)
		{
			lcs.assign(a.size() + 1, vector <int>(b.size() + 1, 0));

			for (int i = 1; i < a.size() + 1; i++) {
				for (int j = 1; j < b.size() + 1; j++) {
					if (a[i - 1] == b[j - 1])
						lcs[i][j] = lcs[i - 1][j - 1] + 1;
					else
						lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
				}
			}
		}
	private:
		vector <vector <int>> lcs;
};

int main(int argc, char **argv)
{
	solution s;
	string a = "ABCDFGHJQZ", b = "ABCDEFGIJKRXYZ";

	s.fill_lcs_table(a, b);
	string ret = s.diff(a, b, a.size(), b.size());

	cout << "diff of string " << a << " and " << b << " is " << ret << endl;

	exit(EXIT_SUCCESS);
}
