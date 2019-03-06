#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution {
public:
	void word_break(vector <string> &dict, string input, string line_break, vector <string> &result)
	{
		if (input.size() == 0) {
			result.push_back(line_break);
			return;
		}

		//for every possible substr of the input
		for (int i = 1; i <= input.size(); i++) {
			string word = input.substr(0, i);
			if (find(dict.begin(), dict.end(), word) != dict.end()) {
				line_break += word + ' ';
				word_break(dict, input.substr(i), line_break, result);
			}
		}
	}
};

int main(int argc, char **argv)
{
	solution s;
	vector <string> dict = {"this", "th", "is", "famous", "Word", "break",
		"b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem"};

	string line_break;
	vector <string> result;
	string input = "Wordbreakproblem";
	s.word_break(dict, input, line_break, result);
	for (auto &i : result)
		cout << i << endl;

	exit(EXIT_SUCCESS);
}
