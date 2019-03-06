#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct range {
	int lower;
	int upper;
	range(int x, int y) : lower(x), upper(y)
	{}
};

class solution {
public:
	void amazing_idx(vector <int> &a, int &max_idx)
	{
		vector <range> ranges;

		get_all_valid_ranges(a, ranges);
		get_max_cnt_from_ranges(a.size(), ranges, max_idx);
	}

	void amazing_idx_bf(vector <int> &a, int &idx)
	{
		int max_cnt = 0;

		for (int i = 0; i < a.size(); i++) {
			int cnt = 0;
			for (int j = i; j < a.size(); j++) {
				if (a[j] <= (j - i))
					cnt++;
			}

			for (int j = 0; j < i; j++) {
				if (a[j] <= (a.size() - i + j))
					cnt++;
			}

			if (max_cnt < cnt) {
				max_cnt = cnt;
				idx = i;
			}
		}
	}

private:
	void get_all_valid_ranges(vector <int> &a, vector <range> &ranges)
	{
		int n = a.size();
		for (int i = 0; i < n; i++) {
			if (a[i] >= n)
				continue;

			if (a[i] > i) {
				/*
					array: {X, X, X, 4, X, X, X, X}
					idx:    0  1  2  3  4  5  6  7
					range:              |--------|
				 */
				int end_idx = n - a[i] + i;
				ranges.push_back(range(i + 1, end_idx));
			}
			else {
				/*
					array: {X, X, X, 2, X, X, X, X}
					idx:    0  1  2  3  4  5  6  7
					ranges: |--|        |--------|
				 */
				int end_idx = i - a[i];
				ranges.push_back(range(0, end_idx));
				if (i + 1 < n - 1) { //WARNING, i + 1 may exceed array range.
					ranges.push_back(range(i + 1, n - 1));
				}
			}
		}
	}

	void get_max_cnt_from_ranges(int size, vector <range> &ranges, int &max_idx)
	{
		vector <int> range_lower_set, range_upper_set;

		for (auto &i : ranges) {
			range_lower_set.push_back(i.lower);
			range_upper_set.push_back(i.upper);
		}
		sort(range_lower_set.begin(), range_lower_set.end());
		sort(range_upper_set.begin(), range_upper_set.end());

		max_idx = 0; //there maybe no valid range at all
		int max_cnt = 0;
		for (int idx = 0; idx < size; idx++) {
			auto start = upper_bound(range_lower_set.begin(), range_lower_set.end(), idx);
			int ranges_lower_earlier_than_curr_idx = distance(range_lower_set.begin(), start);

			auto end = lower_bound(range_upper_set.begin(), range_upper_set.end(), idx);
			//lower_bound will not include target itself, which is the desired result.
			int ranges_upper_earlier_than_curr_idx = distance(range_upper_set.begin(), end);
			if (max_cnt < ranges_lower_earlier_than_curr_idx - ranges_upper_earlier_than_curr_idx) {
				max_cnt = ranges_lower_earlier_than_curr_idx - ranges_upper_earlier_than_curr_idx;
				max_idx = idx;
			}
		}
	}
};


int main(int argc, char **argv)
{
	vector <vector <int>> test_vectors = {
		{},
		{1},
		{1, 2},
		{1, 0, 0},
		{0, 1, 2, 3},
		{4, 4},
		{4, 0, 1},
		{4, 2, 8, 2, 4, 5, 3},
		{9, 8, 7, 6, 5, 4, 3, 2, 1},
		{0, 0, 0, 0, 0, 0},
		{1, 2, 3, 4, 5, 1, 2, 9, 10, 11, 1, 2, 3, 4, 5, 6},
	};

	solution s;
	for (auto &i : test_vectors) {
		int idx;
		s.amazing_idx(i, idx);
		cout << "for array {";
		for (auto &j : i)
			cout << j << ", ";
		cout << "}, amazing num start from idx " << idx;
		s.amazing_idx_bf(i, idx);
		cout << ", while brutal force get idx " << idx << endl;
	}
}
