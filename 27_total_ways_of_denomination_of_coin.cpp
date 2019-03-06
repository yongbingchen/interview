#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		int total_ways(vector <int> &denoms, int idx, int val)
		{
			if (val == 0)
				return 1;


			if (idx < 0)
				return 0;
			if (val < 0)
				return 0;
			int total_w = 0;
			int total_coins = val / denoms[idx];
			for (int i = 0; i < total_coins + 1; i++) {
				total_w += total_ways(denoms, idx - 1, val - i * denoms[idx]);
			}

			return total_w;
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <int> denoms = {1, 3, 5, 7};

	for (int i = 8; i < 15; i++) {
		int ret = s.total_ways(denoms, denoms.size() - 1, i);
		cout << "for val " << i << ", there're total " << ret << " ways of denomination" << endl;
	}

	exit(EXIT_SUCCESS);
}
