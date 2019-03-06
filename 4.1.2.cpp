#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class solution {
	public:
		int longest_valid_parentheses(const string &str)
		{
			stack <char> stk;
			int max_len = 0;
			int len = 0;

			for (auto &i : str) {
				if (i == '(')
					stk.push(i);
				else {
					if (!stk.empty() && stk.top() == '(') {
						len += 2;
						stk.pop();
					}
					else {
						max_len = max(max_len, len);
						len = 0;
						while(!stk.empty())
							stk.pop();
					}
					//remember put it here too.
					max_len = max(max_len, len);
				}
			}

			return max_len;
		}
};

int main(int argc, char **argv)
{
	solution a;
	vector <string> test_vectors = {
		"(()",
		")()())",
		")((((()))))())"
	};

	if (test_vectors[0] == "(()")
		cout << "can compare strings with == too." << endl;

	for (auto s : test_vectors)
		cout << "for test string " << s << " longest valid parentheses is " << a.longest_valid_parentheses(s) << endl;
}
