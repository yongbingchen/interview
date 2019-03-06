#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		int gas_station(vector <int> &gas, vector <int> &cost)
		{
			int total_gas_left = 0;
			int starting_station = -1;
			int gas_left_from_start = 0;
			for (int i = 1; i < gas.size() + 1; i++) {
				total_gas_left += (gas[i] - cost[i]);
				gas_left_from_start += (gas[i] - cost[i]);
				if (gas_left_from_start < 0) {
					//last start station is not feasible.
					//try from next station.
					starting_station = i + 1;
					gas_left_from_start = 0;
				}
			}

			if (total_gas_left < 0)
				return -1;

			return starting_station;
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <int> gas = {1, 2, 3, 4, 5, 6, 7, 8, 10};
	vector <int> cost = {9, 8, 7, 4, 5, 6, 3, 2, 1};
	int ret = s.gas_station(gas, cost);
	cout << "starting from station " << ret << endl;
	exit(EXIT_SUCCESS);
}
