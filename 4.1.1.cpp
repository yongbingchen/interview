#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class solution {
	public:
		bool is_valid_parentheses(const string &s)
		{
			vector <char> left = {'(', '[', '{'};
			vector <char> right = {')', ']', '}'};

			stack <char> unmatched;

			for (auto &c : s) {
				auto it = find(left.begin(), left.end(), c);
				if (it != left.end()) {
					unmatched.push(c);
				}
				else {
					it = find(right.begin(), right.end(), c);
					int idx = distance(right.begin(), it);
					if (unmatched.empty() || unmatched.top() != left[idx])
						return false;
					unmatched.pop();
				}
			}

			//beaware of this case:
			return unmatched.empty();
		}
};

int main(int argc, char **argv)
{
	solution a;

	vector <string> test_vectors = {
		"({{{[]}}})",
		"(({{{[]}}})",
		"[{((((())))))]}}"
	};

	for (auto s : test_vectors)
		cout << "string " << s << " is valid parenthese " << a.is_valid_parentheses(s) << endl;
}
