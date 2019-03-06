#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class solution {
	public:
		int max_sum(vector <int> &a, int idx, int prev_idx)
		{
			if (idx < 0)
				return 0;
			if (prev_idx != idx + 1) {
				int with_curr = max_sum(a, idx - 1, idx) + a[idx];
				int wo_curr = max_sum(a, idx - 1, prev_idx);
				return max(with_curr, wo_curr);
			}
			return max_sum(a, idx - 1, prev_idx);
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <int> a = {1, 2, 9, 4, 5, 0, 4, 11, 6};

	//adjacent means the index is adjacent, not the value.
	int ret = s.max_sum(a, a.size() - 1, INT_MIN);
	cout << ret << endl;

	exit(EXIT_SUCCESS);
}
