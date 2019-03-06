//Find the longest substring with K unique characters.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class solution {
	public:
		string longest_subseq(string input, int idx, unordered_map <char, bool> &set, int k)
		{
			if (idx == input.size())
				return "";

			string with_curr, wo_curr;
			if (set.find(input[idx]) == set.end()) {
				wo_curr = longest_subseq(input, idx + 1, set, k);
				if (set.size() < k) {
					set[input[idx]] = true;
					with_curr = input[idx] + longest_subseq(input, idx + 1, set, k);
					set.erase(input[idx]);
				}
			}
			else {
				with_curr = input[idx] + longest_subseq(input, idx + 1, set, k);
			}

			return with_curr.size() > wo_curr.size() ? with_curr : wo_curr;
		}

		string longest_substr(string input, vector <char> &char_set, int k)
		{
			vector <char> curr;
			vector <vector <char>> all_combinations;
			get_all_combination(char_set, curr, all_combinations, 0, k);

			string max_len;
			for (auto &i : all_combinations) {
				unordered_map <char, bool> this_set;
				for (auto &j : i)
					this_set[j] = true;

				string curr = longest_substr_fixed_set(input, this_set, k);
				if (curr.size() > max_len.size())
					max_len = curr;
			}

			return max_len;
		}

	private:
		//!IMPORTANT! this is a generic method to get len 'm' combination of a 'n' sized set.
		void get_all_combination(vector <char> &set, vector <char> &curr, vector <vector <char>> &all_combinations, int idx, int m)
		{
			if (m == 0) {
				all_combinations.push_back(curr);
				return;
			}

			for (int i = idx; i < set.size(); i++) {
				curr.push_back(set[i]);
				get_all_combination(set, curr, all_combinations, i + 1, m - 1);
				curr.pop_back(); //backtracking
			}
		}

		string longest_substr_fixed_set(string input, unordered_map <char, bool> &set, int k)
		{
			vector <string> substr(input.size() + 1, "");
			string output;
			for (int i = 0; i < input.size(); i++) {
				if (set[input[i]]) {
					substr[i + 1] = substr[i] + input[i]; //this is the key diff between subseq and substr
					if (substr[i + 1].size() > output.size()) {
						output = substr[i + 1];
					}
				}
			}

			return output;
		}
};

int main(int argc, char **argv)
{
	string input = "aabacbebebe";
	solution s;

	for (int k = 1; k < 4; k++) {
		unordered_map <char, bool> set;
		string output = s.longest_subseq(input, 0, set, k);
		cout << k << ", " << output << endl;
	}

	//get char set from input string is trivial, so just set it as an input param.
	vector <char> char_set = {'a', 'b', 'c', 'e'};
	for (int k = 1; k < 4; k++) {
		string output = s.longest_substr(input, char_set, k);
		cout << k << ", " << output << endl;
	}

	exit(EXIT_SUCCESS);
}
