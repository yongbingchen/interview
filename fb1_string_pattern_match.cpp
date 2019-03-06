#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class solution {
	public:
		void pattern_expand(string input, int idx, vector <string> &pattern,
				unordered_map <string, vector <string>> &map, vector <string> &path,
				vector <vector <string>> &result)
		{
			if (idx == input.size()) {
				result.push_back(path);
				return;
			}

			for (int i = 1; i < input.size() - idx + 1; i++) {
				string prefix = input.substr(idx, i);
				if (map.find(prefix) != map.end()) {
					for (auto &s : map[prefix]) {
						path.push_back(s);
						pattern_expand(input, idx + i, pattern, map, path, result);
						path.pop_back();
					}
				}
			}
		}
};

int main(int argc, char **argv)
{
	solution s;

	vector <string> pattern = {"1", "2", "12", "3"};
	unordered_map <string, vector <string>> map;
	map["1"] = vector <string> {"A", "B", "C"};
	map["2"] = vector <string> {"D", "E"};
	map["12"] = vector <string> {"X"};
	map["3"] = vector <string> {"P", "Q"};

	vector <string> path;
	vector <vector <string>> result;
	string input = "123";
	s.pattern_expand(input, 0, pattern, map, path, result);
	for (auto &i : result) {
		for (auto &j : i)
			cout << j << ", ";
		cout << endl;
	}

	exit(EXIT_SUCCESS);
}
