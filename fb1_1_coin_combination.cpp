#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class solution {
	public:
		void get_path(int sum, vector <int> &coins, vector <int> &curr,
				vector <int> &path, unordered_map <int, bool> &visited)
		{
			if (sum == 0) {
				for (auto &i : curr) {
					path.push_back(i);
				}
				return;
			}

			//visited[sum] = true; this place can not filter out duplicate
			curr.push_back(sum);
			for (auto &i : coins) {
				for (int j = 1; j <= sum / i; j++) { //j = 0 will not trigger loop, and miss '=' in second statement will miss some case, thus loop will not converge to sum == 0;
					if (visited.find(sum - i * j) == visited.end()) { //!CAUTION, correct way to use map as flags
						visited[sum - i * j] = true;
						//curr.push_back(sum - i * j); put backtracking here will miss the original sum (like'1000')
						get_path(sum - i * j, coins, curr, path, visited);
						//curr.pop_back();
					}
				}
			}
			curr.pop_back();
		}
};

int main(int argc, char **argv)
{

	solution s;

	vector <int> path;
	vector <int> curr;
	unordered_map <int, bool> visited;
	vector <int> coins = {10, 15, 55};
	s.get_path(1000, coins, curr, path, visited);
	sort(path.begin(), path.end());
	for (auto &i : path)
		cout << i << endl;
}
