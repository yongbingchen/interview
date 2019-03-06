#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class solution {
	public:
		int min_coins(vector <int> &denoms, int idx, int val)
		{
			if (idx < 0)
				return INT_MAX;
			if (val < 0)
				return INT_MAX;
			if (val == 0) //THIS is the key to stop the recursive.
				return 0;

			int min_c = INT_MAX;
			int nums = val / denoms[idx];
			for (int i = 0; i < nums + 1; i++) {
				int tmp = min_coins(denoms, idx - 1, val - i * denoms[idx]);
				if (tmp != INT_MAX) //BEWARE of integer overflow, INT_MAX + 1 = INT_MIN
					tmp += i;
				min_c = min(min_c, tmp);
			}

			return min_c;
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <int> denoms = {1, 3, 5, 7};

	for (int i = 15; i < 25; i++) {
		int ret = s.min_coins(denoms, denoms.size() - 1, i);
		cout << "for total val " << i << ", the minimum coins needed is " << ret << endl;
	}

	exit(EXIT_SUCCESS);
}
