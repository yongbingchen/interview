#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution {
public:
	void find_4_sum(vector <int> &a, vector <vector <int>> &result)
	{
		sort(a.begin(), a.end());
		vector <int> curr;
		find_sum(a.begin(), a.end(), 4, 0, curr, result);
	}

private:
	template <typename iterator>
	void find_sum(iterator begin, iterator end, int k, int sum, vector <int> &curr,  vector <vector <int>> &result)
	{
		if (k == 0) {
			if (sum == 0) {
				result.push_back(curr);
			}
			return;
		}
		if (begin == end)
			return;

		for (auto it = begin; it != end; it++) {
			curr.push_back(*it);
			find_sum(next(it), end, k - 1, sum - *it, curr, result);
			curr.pop_back();
		}
	}
};

int main(int argc, char **argv)
{
	vector <int> a = {1, 0, -1, 0, -2, 2};
	vector <vector <int>> result;
	solution s;
	s.find_4_sum(a, result);

	for (auto &i : result) {
		for (auto &j : i)
			cout << j << ", ";
		cout << endl;
	}
}
