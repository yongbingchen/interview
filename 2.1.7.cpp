#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class solution {
	public:
		pair <int, int> two_sum_brutal_force(vector <int> &a, const int target)
		{
			for (int i = 0; i < a.size(); i++) {
				for (int j = 0; j < a.size(); j++)
					if (a[i] + a[j] == target)
						return pair<int, int>(i + 1, j + 1);
			}
			return pair<int, int>(0, 0);
		}
		//sort will change element index, so it's not feasible.
		pair <int, int> two_sum(vector <int> &a, int target)
		{
			unordered_map <int, int> map;

			int n = a.size();
			for (int i = 0; i < n; i++) {
				map[a[i]] = i + 1; //map allow index to be negative, while vector can not
			}

			for (int i = 0; i < n; i++) {
				if (map.find(target - a[i]) != map.end()) {
					return pair <int, int>(i + 1, map[target - a[i]]);
				}
			}

			return pair <int, int>(-1, -1);
		}

};

int main(int argc, char **argv)
{
	vector <int> t = {2, 7, 11, 15};
	solution s;
	pair <int, int> ret = s.two_sum(t, 9);
	cout << "result " << ret.first << ", " << ret.second << endl;
	exit(EXIT_SUCCESS);
}
