#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		bool subset_sum(vector <int> &a, int idx, int sum)
		{
			if (sum == 0)
				return true;

			if (idx == 0)
				return sum == a[0];

			bool with_curr = subset_sum(a, idx - 1, sum - a[idx]);
			if (with_curr)
				return true;
			bool wo_curr = subset_sum(a, idx - 1, sum);
			return wo_curr;
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <int> a = {7, 3, 2, 5, 8};

	bool can = s.subset_sum(a, a.size() - 1, 14);
	cout << can << endl;

	exit(EXIT_SUCCESS);
}
