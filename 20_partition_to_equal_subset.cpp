#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		bool partition_set(vector <int> &a)
		{
			int sum = 0;
			for (auto &i : a)
				sum += i;
			if (sum % 2 != 0)
				return false;

			return partition_set(a, a.size() - 1, sum / 2);
		}
	private:
		bool partition_set(vector <int> &a, int idx, int sum)
		{
			if (sum == 0)
				return true;

			if (idx == 0)
				return sum == a[0];

			bool with_curr = partition_set(a, idx - 1, sum - a[idx]);
			if (with_curr)
				return true;
			bool wo_curr = partition_set(a, idx - 1, sum);
			return wo_curr;
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <int> a = {3, 1, 1, 2, 2, 1};

	bool can = s.partition_set(a);
	cout << can << endl;

	exit(EXIT_SUCCESS);
}
