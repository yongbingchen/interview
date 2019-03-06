#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class solution {
public:
	int special_pairs(vector <string> &input)
	{
		unordered_map <string, string> pool;

		int matched = 0;
		for (auto &s : input) {
			if (pool.find(s) != pool.end()) {
				cout << s << " matched " << pool[s] << endl;
				matched++;
			}
			else {
				vector <string> all_variant;
				get_all_variant(s, 0, all_variant);
				for (auto &i : all_variant)
					pool[i] = s;
			}
		}

		return matched * 2;
	}
private:
	void get_all_variant(string s, int idx, vector <string> &output)
	{
		if (idx == s.size())
			return;

		for (int j = idx; j < s.size(); j += 2) {
			swap(s[idx], s[j]);
			output.push_back(s);
			get_all_variant(s, idx + 1, output);
			swap(s[idx], s[j]);
		}
	}
};

int main(int argc, char **argv)
{
	vector <vector <string>> test_input = {
		{"abcd", "cbad", "bacd"},
		{"abcd", "acbd", "adcb", "cdba", "bcda", "badc"},
	};

	solution s;
	for (auto &v: test_input) {
		int ret = s.special_pairs(v);
		cout << ret << endl;
	}
}
