#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class solution {
	public:
		int min_sum_partition(vector <int> &a, int idx, int subset_0, int subset_1)
		{
			if (idx < 0) {
				return abs(subset_0 - subset_1);
			}

			int with_curr = min_sum_partition(a, idx - 1, subset_0 + a[idx], subset_1);
			int wo_curr = min_sum_partition(a, idx - 1, subset_0, subset_1 + a[idx]);
			return min(with_curr, wo_curr);
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <int> a = {10, 20, 15, 5, 25};

	int ret = s.min_sum_partition(a, a.size() - 1, 0, 0);
	cout << ret << endl;

	exit(EXIT_SUCCESS);
}
