#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class solution {
	public:
		int calc_polish_notation(vector <string> &strs)
		{
			stack <string> stk;
			int result;

			for (auto s : strs) {
				if (!is_operator(s)) {
					stk.push(s);
				}
				else {
					if (stk.empty())
						return 0;


					/*! CAUTION: pop() can not get top element*/
					int x = stoi(stk.top());
					stk.pop();
					int y = stoi(stk.top());
					stk.pop();
					if (s == "+")
						result = x + y;
					else if (s == "-")
						result = y - x;
					else if (s == "*")
						result = x * y;
					else if (s == "/")
						result = y / x;

					stk.push(to_string(result));
				}
			}

			return stoi(stk.top());
		}
	private:
		bool is_operator(const string &s)
		{
			if (s.size() != 1)
				return false;

			if (s != "+" && s != "-" && s != "*" && s != "/")
				return false;

			return true;
		}
};

int main(int argc, char **argv)
{
	solution a;

	vector <vector <string>> test_vectors = {
		{"2", "1", "+", "3", "*"},
		{"4", "13", "5", "/", "+"}
	};

	for (auto s : test_vectors) {
		cout << "for string ";
		for (auto c : s)
			cout << c << ", ";
		cout << " result is " << a.calc_polish_notation(s) << endl;
	}
}

