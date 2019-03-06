#include <iostream>
#include <vector>
#include <string>

using namespace std;

class solution {
public:
	void translate(string input, int idx, vector <char> &table, string curr, vector <string> &output)
	{
		if (idx == input.size()) {
			output.push_back(curr);
			return;
		}

		string sub = input.substr(idx, 1);
		curr.push_back(table[stoi(sub)]);
		translate(input, idx + 1, table, curr, output);
		curr.pop_back(); //backtracking

		if (idx <= input.size() - 2) {
			sub = input.substr(idx, 2);
			if (stoi(sub) < table.size()) { //WARNING!, trap here, must check array idx before use it
				curr.push_back(table[stoi(sub)]);
				translate(input, idx + 2, table, curr, output);
				curr.pop_back();
			}
		}
	}
};

int main(int argc, char **argv)
{
	vector <char> table = {'*'}; //use a placeholder here to simplify the code.
	for (int i = 0; i < 26; i++)
		table.push_back('a' + i);

	solution s;
	string curr;
	string input = "123123123";
	vector <string> output;
	s.translate(input, 0, table, curr, output);
	for (auto &i : output)
		cout << i << endl;
}
