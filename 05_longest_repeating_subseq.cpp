#include <iostream>
#include <vector>
#include <string>

using namespace std;

class solution {
	public:
		int len_of_longest_repeating_subseq(string a, int len_m, int len_n)
		{
			if (len_m == 0 || len_n == 0)
				return 0;

			if (a[len_m - 1] == a[len_n - 1] && len_m != len_n)
				return len_of_longest_repeating_subseq(a, len_m - 1, len_n - 1) + 1;


			return max(len_of_longest_repeating_subseq(a, len_m - 1, len_n),
					len_of_longest_repeating_subseq(a, len_m, len_n - 1));
		}

		string longest_repeating_subseq(string a, int len_m, int len_n)
		{
			if (len_m == 0 || len_n == 0)
				return string("");

			if (a[len_m - 1] == a[len_n - 1] && len_m != len_n)
				return longest_repeating_subseq(a, len_m - 1, len_n - 1) + a[len_m - 1];

			if (lrc[len_m][len_n - 1] > lrc[len_m - 1][len_n])
				return longest_repeating_subseq(a, len_m, len_n - 1);
			else
				return longest_repeating_subseq(a, len_m - 1, len_n);
		}

		void build_lrc_table(string a)
		{
			lrc.assign(a.size() + 1, vector <int> (a.size() + 1, 0));
			for (int len_m = 1; len_m < a.size() + 1; len_m++) {
				for (int len_n = 1; len_n < a.size() + 1; len_n++) {
					if (a[len_m - 1] == a[len_n - 1] && len_m != len_n)
						lrc[len_m][len_n] = lrc[len_m - 1][len_n - 1] + 1;
					else
						lrc[len_m][len_n] = max(lrc[len_m - 1][len_n], lrc[len_m][len_n - 1]);
					//cout << "a["<<len_m<<"]=" << a[len_m] << ", a[" <<len_n<<"] = " <<a[len_n] <<", lrc[len_m][len_n] = " <<lrc[len_m][len_n] << endl;
				}
			}
		}

	private:
		vector <vector <int>> lrc;
};

int main(int argc, char **argv)
{
	solution s;
	string a = "ATACTCGGA";
	cout << "len of longest repeating subsequnce of " << a << " is " << s.len_of_longest_repeating_subseq(a, a.size() - 1, a.size() - 1) << endl;

	s.build_lrc_table(a);
	string ret = s.longest_repeating_subseq(a, a.size() - 1, a.size() - 1);

	cout << "the longest repeating subsequnce is " << ret << endl;
	exit(EXIT_SUCCESS);
}
