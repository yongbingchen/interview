#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class solution {
public:
	void max_sum(vector <int> &a, vector <int> &output)
	{
		vector <int> sum(a.size(), 0);
		vector <vector <int>> max_sub(a.size());

		int max_sum = INT_MIN;
		max_sub[1].push_back(a[0]);
		max_sub[1].push_back(a[1]);
		output = max_sub[1]; //init value;
		sum[1] = a[0] + a[1];
		for (int i = 2; i < a.size(); i++) {
			if (sum[i - 1] + a[i] > a[i]) {
				max_sub[i] = max_sub[i - 1];
				sum[i] = sum[i - 1];
			}
			max_sub[i].push_back(a[i]);
			sum[i] += a[i];
			if (max_sub[i].size() > 1) {
				if (sum[i] > max_sum) {
					max_sum = sum[i];
					output = max_sub[i];
				}
			}
		}
	}

	void max_sum_brutal_force(vector <int> &a, vector <int> &output)
	{
		vector <vector <int>> max_sub_array_ended_with_curr(a.size());
		vector <int> curr(a.size(), 0);

		int max_sum = INT_MIN;
		for (int i = 1; i < a.size(); i++) {
			max_sub_array_ended_with_curr[i].clear();
			max_sub_array_ended_with_curr[i].push_back(a[i - 1]);
			max_sub_array_ended_with_curr[i].push_back(a[i]);
			curr[i] = a[i - 1] + a[i];
			if (max_sum < curr[i]) {
				max_sum = curr[i];
				output = max_sub_array_ended_with_curr[i];
			}
			for (int j = i + 1; j < a.size(); j++) {
				curr[j] = curr[j - 1] + a[j];
				max_sub_array_ended_with_curr[j] = max_sub_array_ended_with_curr[j - 1];
				max_sub_array_ended_with_curr[j].push_back(a[j]);
				if (max_sum < curr[j]) {
					max_sum = curr[j];
					output = max_sub_array_ended_with_curr[j];
				}
			}
		}
	}
};

int main(int argc, char **argv)
{
	vector <vector <int>> test_vectors = {
		{-2, -1, -3, -4, -1},
		{-2, -1, 3, 4, -1, -3},
		{-2, -1, 3, -1, -3},
		{-2, -1, 3, 4, -1, -3, 5, 6},
		{-2, -1, 3, 4, 5, -1, -3, 5, 6},
	};
	solution s;

	for (auto &t : test_vectors) {
		vector <int> output;
		s.max_sum(t, output);
		for (auto &i : output)
			cout << i << ", ";
		cout << endl;
	}
}
