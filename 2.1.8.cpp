#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class solution {
	public:
		vector <vector <int>> threesum(vector <int> &a, int target)
		{
			vector <vector <int>> result;
			sort(a.begin(), a.end());
			for (int i = 0; i < a.size(); i++) {
				//only search subset after curr element.
				pair <int, int> ret = twosum(a, i + 1, target - a[i]);
				if (ret.first != -1) {
					vector <int> t;
					t.push_back(a[i]);
					t.push_back(a[ret.first]);
					t.push_back(a[ret.second]);
					result.push_back(t);
				}
			}
			return result;
		}
	private:
		pair <int, int> twosum(vector <int> &a, int idx, int target)
		{
			unordered_map <int, int> map;
			for (int i = idx; i < a.size(); i++) {
				map[a[i]] = i;
			}

			for (int i = idx; i < a.size(); i++) {
				if (map.find(target - a[i]) != map.end()) {
					//tricky point here!
					if (target - a[i] != a[i]) {
						int second = map[target - a[i]];
						return pair <int, int>(i, second);
					}
				}
			}

			return pair <int, int>(-1, -1);
		}

};

int main(int argc, char **argv)
{
	vector <int> test = {-1, 0, 1, 2, -1, -4};
	solution s;
	vector <vector <int>> result = s.threesum(test, 0);
	for (const auto &i : result) {
		for (const auto &j : i)
			cout << j << ", ";
		cout << endl;
	}
	exit(EXIT_SUCCESS);
}
