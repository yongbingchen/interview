#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class solution {
	public:
		int max_subarray_sum(vector <int> &a)
		{
			int max_sub_array_sum = a[0];
			int max_sub_array_sum_with_curr = a[0];
			for (int i = 1; i < a.size(); i++) {
				max_sub_array_sum_with_curr += a[i];
				//KEY point is here, if curr subarray's sum is less than a[i] itslef, then start over.
				max_sub_array_sum_with_curr = max(max_sub_array_sum_with_curr, a[i]);
				max_sub_array_sum = max(max_sub_array_sum, max_sub_array_sum_with_curr);
			}

			return max_sub_array_sum;
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

	int ret = s.max_subarray_sum(a);
	cout << ret << endl;

	exit(EXIT_SUCCESS);
}
