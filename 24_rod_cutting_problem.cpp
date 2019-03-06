#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class solution {
public:
	int max_profit(vector <pair <int, int>> &price, int idx, int len)
	{
		if (len <= 0)
			return 0;
		if (idx < 0)
			return 0;


		int max_p = 0;
		int total_cuts  = len / price[idx].first;
		for (int i = 0; i < total_cuts + 1; /*+1 to cover no cut from curr len case*/ i++) {
			int tmp = max_profit(price, idx - 1, len - i * price[idx].first) +
				i * price[idx].second;
			cout << "for curr len " << len << ", cut by curr sub len " << price[idx].first << " by " << i << " times, the profit is " << tmp << endl;
			max_p = max(max_p, tmp);
		}

		return max_p;
	}
};

int main(int argc, char **argv)
{
	solution s;
	vector <pair <int, int>> price = {
		pair <int, int>(1, 1),
		pair <int, int>(2, 5),
		pair <int, int>(3, 8),
		pair <int, int>(4, 9),
		pair <int, int>(5, 10),
		pair <int, int>(6, 17),
		pair <int, int>(7, 17),
		pair <int, int>(8, 20),
	};

	int ret = s.max_profit(price, price.size() - 1, 4);
	cout << ret << endl;

	exit(EXIT_SUCCESS);
}
