#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution {
	public:
		vector <vector <int>> get_all_combinations(const int n, const int k)
		{
			/* NOT this way.
			int total_combinations = 1;

			for (int i = 0; i < k; i++)
				int permutation_n_k *= (n - k);

			for (int i = 1; i < k + 1; i++)
				int permutation_k *= k;

			total_combination = permutation_n_k / permutation_k;
			*/
#if 0
			vector <bool> selected(n, false);
			vector <vector <int>> result;

			fill(selected.begin(), next(selected.begin(), k), true);
			do {
				cout << "current selected is :";
				for (const auto &k : selected)
					cout << k << ", ";
				cout << endl;

				vector <int> one_set = {};
				for (int i = 0; i < n; i++) {
					if (selected[i])
						one_set.push_back(i);
				}
				result.push_back(one_set);

			} while(prev_permutation(selected.begin(), selected.end()));
#endif
			vector <int> set(n);
			vector <int> curr;
			vector <vector <int>> result;
			for (int i = 0; i < n; i++)
				set[i] = i;
			all_combinations(set, curr, result, 0, k);
			return result;
		}
	private:
		void all_combinations(vector <int> &a, vector <int> &curr, vector <vector <int>> &result, int idx, int k)
		{
			if (k == 0) {
				result.push_back(curr);
				return;
			}

			for (int i = idx; i < a.size(); i++) {
				curr.push_back(a[i]);
				all_combinations(a, curr, result, i + 1, k - 1);
				curr.pop_back();
			}
		}
};

int main(int argc, char **argv)
{
	solution s;

	vector <vector <int>> ret = s.get_all_combinations(4, 2);

	for (const auto &i : ret) {
		for (const auto &j : i)
			cout << j << ", ";
		cout << endl;
	}
}
