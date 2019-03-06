#include <iostream>
#include <string>
#include <vector>

using namespace std;

class solution {
	public:
		string shortest_common_superseq(string a, string b, int len_a, int len_b)
		{
			if (len_a == 0 && len_b == 0)
				return string("");
			if (len_a == 0)
				return b.substr(0, len_b);
			if (len_b == 0)
				return a.substr(0, len_a);

			if (a[len_a - 1] == b[len_b - 1])
				return shortest_common_superseq(a, b, len_a - 1, len_b - 1) + a[len_a - 1];
			if (scs[len_a - 1][len_b] > scs[len_a][len_b - 1])
				return shortest_common_superseq(a, b, len_a, len_b - 1) + b[len_b - 1];
			else
				return shortest_common_superseq(a, b, len_a - 1, len_b) + a[len_a - 1];
		}

		void fill_scs(string a, string b, int len_a, int len_b)
		{
			scs.assign(a.size() + 1, vector <int>(b.size() + 1, 0));
			for (int i = 1; i < a.size() + 1; i++) {
				for (int j = 1; j < b.size() + 1; j++) {
					if (a[i - 1] == b[j - 1])
						scs[i][j] = scs[i - 1][j - 1] + 1;
					else
						scs[i][j] = min(scs[i - 1][j] + 1, scs[i][j - 1] + 1);
				}
			}
		}

	private:
		vector <vector <int>> scs;


};

int main(int argc, char **argv)
{
	solution s;
	string a = "ABCBDBA", b = "BDCABA";
	s.fill_scs(a, b, a.size(), b.size());
	cout << "shortest common super sequence of " << a << " and " << b << " is " << s.shortest_common_superseq(a, b, a.size(), b.size()) << endl;
	exit(EXIT_SUCCESS);
}
