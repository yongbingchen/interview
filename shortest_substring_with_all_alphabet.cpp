#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class solution {
public:
	string shortest_substr(string input, string alphabet)
	{
		string ret;
		int min_size = input.size();
		for (int i = 0; i < input.size(); i++) {
			string sub = find_substr(input, i, alphabet);
			if (sub.size() != 0  && sub.size() < min_size) {
				ret = sub;
				min_size = ret.size();
			}
		}

		return ret;
	}

private:
	string find_substr(string input, int idx, string alphabet)
	{
		unordered_map <char, bool> used;
		for (auto &c : alphabet)
			used[c] = false;

		string sub;
		for (int i = idx; i < input.size(); i++) {
			used[input[i]] = true;
			sub += input[i];
			bool all_char_present = true;
			for (auto &j : used) {
				if (!j.second) {
					all_char_present = false;
					break;
				}
			}
			if (all_char_present)
				return sub;
		}

		return "";
	}
};


int main(int argc, char **argv)
{
	string input = "abbcac";
	string alphabet = "abc";
	solution s;
	string ret = s.shortest_substr(input, alphabet);
	cout << ret << endl;
}
