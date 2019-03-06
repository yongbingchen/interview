#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class solution {
	public:
		vector <vector <string>> anagrams(vector <string> &strs)
		{
			vector <vector <string>> result;
			unordered_map <string, vector <string>> map;

			int len = strs.size();
			for (auto &s : strs) {
				//CAUTION! how to copy a string in c++;
				string tmp = s;
				sort(tmp.begin(), tmp.end());
				map[tmp].push_back(s);
			}
			for (auto it = map.begin(); it != map.end(); it++) {
				if (it->second.size() > 1)
					result.push_back(it->second);
			}

			return result;
		}
};

int main(int argc, char **argv)
{
	solution s;

	vector <string> strs = {
		"tea",
		"ate",
		"tan",
		"eat",
		"nat",
		"bat"
	};

	vector <vector <string>> result = s.anagrams(strs);

	for (auto j : result) {
		cout << "get anagrams group:" << endl;
		for (auto s : j)
			cout << s << ", ";
		cout << endl;
	}
}
