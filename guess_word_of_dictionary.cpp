#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class solution {
public:
	string guess_word(vector <string> &dict, string t)
	{
		target = t;
		string char_set = get_char_set();
		unordered_map <string, vector <string>> map;
		for (auto &s : dict) {
			string key = s;
			sort(key.begin(), key.end());
			map[key].push_back(s);
		}

		sort(char_set.begin(), char_set.end());
		for (auto &s : map[char_set])
			if (count_matched_chars(s) == s.size())
				return s;

		return "";
	}

private:
	string target;

	string get_char_set(void)
	{
		string ret;
		for (int i = 0; i < 26; i++) {
			vector <char> test(26, 'a' + i);
			//no direct way to convert char vector to string
			int matched = count_matched_chars(string(test.begin(), test.end()));
			for (int j = 0; j < matched; j++)
				ret.push_back('a' + i);
		}

		return ret;
	}

	/*the function as described in the question*/
	int count_matched_chars(string s)
	{
		int cnt = 0;
		int size = s.size();
		unordered_map <int, bool> used;
		for (int i = 0; i < s.size(); i++)
			used[i] = false; //can not init map as a vector

		for (int i = 0; i < target.size(); i++) {
			for (int j = 0; j < s.size(); j++) {
				if (!used[j] && target[i] == s[j]) {
					cnt++;
					used[j] = true;
					break;
				}
			}
		}

		return cnt;
	}

};

int main(int argc, char **argv)
{
	vector <string> dict = {
		"code", "coder", "coding", "codable", "codec", "codecs", "coded",
		"codeless", "codec", "codecs", "codependence", "codex", "codify",
		"codependents", "codes", "code", "coder", "codesign", "codec",
		"codeveloper", "codrive", "codec", "codecs", "codiscovered"
	};

	solution s;
	for (auto &i : dict) {
		string ret = s.guess_word(dict, i);
		cout << "for word " << i << " in dictionary, guess result is " << ret << endl;
	}
}
