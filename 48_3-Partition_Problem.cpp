#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric> //for accumulate

using namespace std;

class solution {
public:
	bool three_partition(vector <int> &a, vector <vector <int>> &result)
	{
		int total = accumulate(a.begin(), a.end(), 0);

		if (total % 3 != 0)
			return false;

		int thirdth = total / 3;
		unordered_map <int, int> lookup;

		for (int i = 0; i < a.size(); i++)
			lookup[a[i]] = i;

		for (int i = 0; i < 3; i++) {
			vector <int> subset;
			partition(a, thirdth, lookup, subset);
			result.push_back(subset);
		}

		return true;
	}
private:
	void partition(vector <int> &a, int sum, unordered_map <int, int> &lookup, vector <int> &result)
	{
		if (sum == 0)
			return;

		if (lookup.find(sum) != lookup.end()) {
			result.push_back(a[lookup[sum]]);
			lookup.erase(sum);
			return;
		}
		auto it = lookup.begin();
		for (; it != lookup.end(); it++) {
			cout << "looking for elem no greater than " << sum << ", while encounter with " << a[it->second] << endl;
			if (a[it->second] <= sum)
				break;
		}
		sum -= a[it->second];
		result.push_back(a[it->second]);
		lookup.erase(it->first);
		partition(a, sum, lookup, result);
	}
};

int main(int argc, char **argv)
{
	vector <int> a = {7, 3, 2, 1, 5, 4, 8};
	solution s;
	vector <vector <int>> result;
	bool ret = s.three_partition(a, result);
	if (ret) {
		for (auto &i : result) {
			for (auto &j : i)
				cout << j << ", ";
			cout << endl;
		}
	}

	exit(EXIT_SUCCESS);
}
