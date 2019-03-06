#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class solution {
	public:
		int len_of_longest_increasing_subseq(vector <int> &a, int start, int prev)
		{
			if (start == a.size())
				return 0;

			int with_curr = 0, wo_curr = 0;
			if (a[start] > prev) {
				with_curr = len_of_longest_increasing_subseq(a, start + 1, a[start]) + 1;
			}
			wo_curr = len_of_longest_increasing_subseq(a, start + 1, prev);
			return max(with_curr, wo_curr);
		}
		vector <int> get_longest_increasing_subseq(vector <int> &a)
		{
			vector <vector <int>> lis(a.size());
			lis[0].push_back(a[0]);

			for (int i = 1; i < a.size(); i++) {
				for (int j = 0; j < a.size(); j++) {
					if (a[i] > a[j] && lis[i].size() < lis[j].size())
						lis[i] = lis[j];
				}
				lis[i].push_back(a[i]);
			}
			int max_idx = 0;
			for (int i = 0; i < a.size(); i++) {
				if (lis[i].size() > lis[max_idx].size())
					max_idx = i;
			}

			return lis[max_idx];
		}

		/*not working! lis is not increasing linerally when sequence size increase!, check the output of final version.
		void get_longest_increasing_subseq(vector <int> &a, int start, vector <int> &result)
		{
			if (start == 0)
				return;
			if (lis_table[start] > lis_table[start - 1]) {
				result.push_back(a[start - 1]);
			}
			get_longest_increasing_subseq(a, start - 1, result);
		}

		void fill_lis_table(vector <int> &a)
		{
			lis_table.clear();
			for (int i = a.size(); i >= 0; i--) {
				int lis = len_of_longest_increasing_subseq(a, i, a.size(), INT_MIN);
				lis_table.push_back(lis);
			}

			for (auto &i : lis_table)
				cout << i << ", ";
			cout << endl;
		}
		*/
};

int main(int argc, char **argv)
{
	solution s;
	vector <int> a = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};

	cout << "length of longest increasing subsequnce is " << s.len_of_longest_increasing_subseq(a, 0, INT_MIN) << endl;

	vector <int> result = s.get_longest_increasing_subseq(a);
	cout << "get longest increasing subseq:" << endl;
	for (auto &i : result)
		cout << i << ", ";
	cout << endl;
	exit(EXIT_SUCCESS);

}
