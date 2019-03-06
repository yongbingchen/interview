#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class solution {
	public:
		string decode(string input)
		{
			stack <char> s;
			for (auto &c : input) {
				if (c != ']')
					s.push(c);
				else {
					string sub;
					while(s.top() != '[') {
						sub = s.top() + sub;
						s.pop();
					}
					s.pop(); //for the '['
					string multiplied;
					for (int i = 0; i < s.top() - '0'; i++)
						multiplied += sub;
					s.pop(); //for the numbers
					for (auto &k : multiplied)
						s.push(k); //store the intermediate result back to stack
				}
			}

			string ret;
			while (!s.empty()) {
				ret = s.top() + ret; //push a string into stack at normal sequence, use this order to restore it.
				s.pop();
			}
			return ret;
		}

};

int main(int argc, char **argv)
{
	string input = "3[a2[bd]g4[ef]h]"; //whenever meet the parentheses matching problem, try stack first.
	solution s;

	string output = s.decode(input);
	cout << output << endl;
}
