#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class solution {
public:
	bool match_pattern(string s, string p, unordered_map <string, string> &map)
	{
		//cout << "s: " << s << ", p: " << p << endl; //un-comment this to see the full iteration.
		if (p.size() == 0 && s.size() == 0)
			return true;

		if (p.size() == 0 || s.size() == 0)
			return false;

		//KEY point of success of this code is using a CHAR as map key, otherwise if use substr from 'str' as key, there're too many branches.
		if (map.find(p.substr(0, 1)) != map.end()) {
			string prefix = map[p.substr(0, 1)];
			if (s.substr(0, prefix.size()).compare(prefix) != 0)
				return false;
			else
				return match_pattern(s.substr(prefix.size()), p.substr(1), map);
		}

		//if no match from current map, try create one key from every substr of 's' (which already removed the matched prefix)
		for (int i = 1; i <= s.size(); i++) {
			string prefix = s.substr(0, i);
			map[p.substr(0, 1)] = prefix;
			if (match_pattern(s.substr(i), p.substr(1), map))
				return true;
			map.erase(p.substr(0, 1)); //backtracking is the key to try all possible substr.
		}

		return false;
	}
};

int main(int argc, char **argv)
{
	vector <string> strs = {
		"codesleepcode",
		"codecodecode",
	};

	vector <string> pattern = {
		"XYX",
		"XXX",
	};

	solution s;

	for (int i = 0; i < strs.size(); i++) {
		for (int j = 0; j < pattern.size(); j++) {
			unordered_map <string, string> map;
			if (s.match_pattern(strs[i], pattern[j], map)) {
				cout << strs[i] << " matches " << pattern[j] << endl;
				for (auto it = map.begin(); it != map.end(); it++)
					cout << it->first << ", " << it->second << endl;
			}
		}
	}

	exit(EXIT_SUCCESS);
}
