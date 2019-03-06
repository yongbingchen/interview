#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class solution {
	public:
		void total_time(vector <int> &tasks, int cooldown, vector <int> &output)
		{
			unordered_map <int, int> map; // to buffer every task's curr cooldown time needed.

			for (int i = 0; i < tasks.size(); i++) {
				if (map.find(tasks[i]) != map.end()) {
					int ticks = map[tasks[i]];
					if (ticks > 0) {
						for (int j = 0; j < ticks;  j++)
							output.push_back(-1);
						for (auto it = map.begin(); it != map.end(); it++)
							it->second -= ticks;
					}
				}
				output.push_back(tasks[i]);
				for (auto it = map.begin(); it != map.end(); it++)
					it->second--;
				map[tasks[i]] = cooldown;
			}
		}
};


int main(int argc, char **argv)
{
	vector <int> tasks = {1, 1, 2, 1, 2, 3, 4, 3, 4, 2, 2, 2, 3};

	solution s;
	vector <int> output;
	int cooldown = 3;
	s.total_time(tasks, cooldown, output);
	for (auto &i : output)
		cout << i << ", ";
	cout << endl;
}
