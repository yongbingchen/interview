#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class solution {
public:
	string repair(string s)
	{
		stack <char> stk;
		string ret;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				stk.push(s[i]);
			}
			else {
				if (!stk.empty() && stk.top() == '(') //CAUTION! call s.top() on an empty stack will cause segmentation fault.
					stk.pop();
				else
					ret += '('; //fix the unmatching parenthese from input.
			}
			ret += s[i];
		}

		while(!stk.empty()) {
			ret += ')';
			stk.pop();
		}

		return ret;
	}

};

int main(int argc, char **argv)
{
	vector <string> input = {
		"(()",
		"())",
		"())))",
		")))()",
		"((((()())",
	};
	solution s;

	for (auto &a : input) {
		string output = s.repair(a);
		cout << "for input " << a << ", get output " << output << endl;
	}
}
