#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class solution {
	public:
		int max_expression_val(vector <int> &a)
		{
			int max_val = INT_MIN;
			for (int i = 1; i < a.size() - 2; i++) {
				int left = max_pair_val(a, 0, i);
				int right = max_pair_val(a, i, a.size() - 1);
				max_val = max(max_val, left + right);
			}

			return max_val;
		}
	private:
		int max_pair_val(vector <int> &a, int start, int end)
		{
			if (end - start < 1)
				return INT_MIN;

			int with_end = a[end] - min_val(a, start, end - 1);
			int wo_end = max_pair_val(a, start, end - 1);

			return max(with_end, wo_end);
		}

		int min_val(vector <int> &a, int start, int end)
		{
			if (end == start)
				return a[end];
			return min(a[end], min_val(a, start, end - 1));
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <int> a = {3, 9, 10, 1, 30, 40};

	cout << s.max_expression_val(a) << endl;
	exit(EXIT_SUCCESS);
}
