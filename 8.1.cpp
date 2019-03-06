#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class solution {
	public:
	void get_all_subsets(vector <int> &a, int idx, vector <int> &curr, vector <vector <int>> &result)
	{
		if (idx == a.size()) {
			result.push_back(curr);
			return;
		}

		curr.push_back(a[idx]);
		get_all_subsets(a, idx + 1, curr, result);
		curr.pop_back();

		get_all_subsets(a, idx + 1, curr, result);
	}

	vector <vector <int>> get_all_subsets(vector <int> &s)
	{
		int n = s.size();
		assert(n < sizeof(int) * 8);

		int total_subsets = 1 << n;
		//!WRONG, all subsets is not a permutation.
		/*
		for (int i = 1; i < n + 1; i++)
			total_subset *= i; */

		int result[total_subsets];
		//!this is the correct way to set it.
		for (int i = 0; i < total_subsets; i++) {
			result[i] = i;
		}

		vector <vector <int>> ret;
		for (int i = 0; i < total_subsets; i++) {
			vector <int> subset = {};
			//!WRONG way to define an empty container.
			//vector <int> subset = {0};
			for (int j = 0; j < sizeof(int) * 8; j++) {
				if (result[i] & (0x1 << j))
					subset.push_back(s[j]);
				//ERROR! without define subset, no instance for ret[i],
				//will cause segmentation fault.
				//	ret[i].push_back(s[j]);
			}
			ret.push_back(subset);
		}

		return ret;
	}
};

int main(int argc, char **argv)
{
	vector <int> t = {1, 2, 3, 4};

	solution s;

	vector <vector <int>> ret = s.get_all_subsets(t);

	for (const auto &i : ret) {
		cout << "get one subset:" << endl;
		for (const auto &j : i)
			cout << j << ", ";
		cout << endl;
	}

	exit(EXIT_SUCCESS);
}


