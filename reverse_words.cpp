#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class solution {
public:
	string reverse_words(string input)
	{
		stack <string> stk;
		int idx = 0;
		string delimiter = " ";
		while(idx < input.size()) {
			string sub = input.substr(idx);
			size_t word_len = sub.find(delimiter);
			if (word_len != string::npos) {
				stk.push(sub.substr(0, word_len));
				idx += (word_len + delimiter.size());
			}
			else { //!CAUTION, no delimiter for last word
				stk.push(sub);
				idx += sub.size();
			}
		}

		string ret;
		while(!stk.empty()) {
			ret = ret + " " + stk.top();
			stk.pop();
		}
		return ret;
	}
};

int main(int argc, char **argv)
{
	string input = "Man bites dog";
	solution s;
	cout << s.reverse_words(input) << endl;
}
