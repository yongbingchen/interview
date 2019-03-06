#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class solution {
public:
	int optim_cost(vector <int> &freq, int start, int end, int level)
	{
		if (start > end)
			return 0;

		if (start == end)
			return freq[start] * level;

		int cost = INT_MAX;
		//choose all node in the sequnce to be the root (including start
		//and end) is the key
		for (int i = start; i <= end; i++) {
			int left_cost = optim_cost(freq, start, i - 1, level + 1);
			int right_cost = optim_cost(freq, i + 1, end, level + 1);
			cost = min(cost, (left_cost + right_cost + freq[i] * level));
		}

		return cost;
	}
};

int main(int argc, char **argv)
{
	solution s;
	vector <int> freq = {25, 10, 20};

	int ret = s.optim_cost(freq, 0, freq.size() - 1, 1);
	cout << ret << endl;

	exit(EXIT_SUCCESS);
}
