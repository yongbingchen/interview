#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		int knapsack(vector <pair <int, int>> &items, int idx, int weight)
		{
			if (weight < 0)
				return 0;

			if (idx == 0) {
				if (weight >= items[idx].second)
					return items[idx].first;
				return 0; //not include this item, then return value is 0.
			}

			if (weight < items[idx].second)
				return knapsack(items, idx - 1, weight);

			int with_this = knapsack(items, idx - 1, weight - items[idx].second);
			int wo_this = knapsack(items, idx - 1, weight);
			return max(with_this + items[idx].first, wo_this);
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <pair <int, int>> items = {{1, 2}, {20, 1}, {5, 2}, {10, 3}, {40, 8}, {15, 7}, {25, 4}};

	int value = s.knapsack(items, items.size() - 1, 10);
	cout << value << endl;

	exit(EXIT_SUCCESS);
}
