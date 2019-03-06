#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>

using namespace std;

class solution {
	public:
		vector <int> closest_three_sum(vector <int> &a, int target)
		{
			sort(a.begin(), a.end());
			unordered_map <int, vector <int>> map;
			for (int i = 0; i < a.size(); i++) {
				vector <int> ret = closest_two_sum(a, i, target - a[i]);
				vector <int> triple = {a[i], ret[1], ret[2]};
				map[ret[0]] = triple;
			}

			int closest = INT_MAX;
			for (auto it = map.begin(); it != map.end(); it++) {
				closest = min(closest, it->first);
			}
			for (auto it = map.begin(); it != map.end(); it++) {
				if (it->first == closest)
					return it->second;
			}
			//! illegal
			//	return vector <int> empty;
		}
	private:
		vector <int> closest_two_sum(vector <int> &a, int idx, int target)
		{
			unordered_map<int, pair <int, int>> map;

			for (int i = idx; i < a.size() - 1; i++) {
				for (int j = i + 1; j < a.size(); j++) {
					if (target - a[j] == a[i]) {
						vector <int> ret = {0, a[i], a[j]};
						return ret;
						//! illegal
						//	return vector <int> (0, a[i], a[j]);
					}
					map[abs(target - a[j])] = pair<int, int>(a[i], a[j]);
				}
			}

			int closest = INT_MAX;
			for (auto it = map.begin(); it != map.end(); it++) {
				closest = min(closest, it->first);
			}
			for (auto it = map.begin(); it != map.end(); it++) {
				if (it->first == closest) {
					vector <int> ret = {closest, it->second.first, it->second.second};
					return ret;
				}
			}
		}
};

int main(int argc, char **argv)
{
	vector <int> test = {-1, 2, 1, -4};
	solution s;

	vector <int> result = s.closest_three_sum(test, 1);
	for (auto &i : result)
		cout << i << ", ";
	cout << endl;
	exit(EXIT_SUCCESS);
}
