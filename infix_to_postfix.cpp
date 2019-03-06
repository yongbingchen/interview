#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class solution {
public:
	int calc(vector <char> &infix, unordered_map <char, int> &var)
	{
		//replace the name with final value
		for (int i = 0; i < infix.size(); i++) {
			if (var.find(infix[i]) != var.end())
				infix[i] = var[infix[i]] + '0';
			else if (!is_operator(infix[i])) {
				cout << "illegal" << endl;
				abort();
			}
		}

		vector <char> postfix;
		infix_to_postfix(infix, postfix);


		stack <char> stk;
		for (auto &c : postfix) {
			if (isdigit(c)) {
				stk.push(c);
			}
			else {
				int operand_1 = stk.top() - '0';
				stk.pop();
				int operand_2 = stk.top() - '0';
				stk.pop();
				if (c == '*')
					stk.push(operand_1 * operand_2 + '0');
				if (c == '+')
					stk.push(operand_1 + operand_2 + '0');
				if (c == '-')
					stk.push(operand_2 - operand_1 + '0');
			}
		}

		return stk.top() - '0';
	}

private:
	/*i: g+p*t-w*p, p: , stk:
	 *i: +p*t-w*p, p:g , stk:
	 *i: p*t-w*p, p:g , stk:+
	 *i: *t-w*p, p:gp , stk:+
	 *i: t-w*p, p:gp , stk:+*
	 *i: -w*p, p:gpt , stk:+*
	 *i: -w*p, p:gpt*+ , stk:
	 *i: w*p, p:gpt*+ , stk:-
	 *i: *p, p:gpt*+w , stk:-
	 *i: p, p:gpt*+w , stk:-*
	 *i: , p:gpt*+wp , stk:-*
	 *i: , p:gpt*+wp*- , stk:
	 *calc loop:
	 *p:gpt*+wp*-, stk:
	 *p:*+wp*-, stk:g,p,t
	 *p:+wp*-, stk:g,(p*t)
	 *p:wp*-, stk:(g + (p*t))
	 *p:*-, stk:(g + (p*t)), w, p
	 *p:-, stk:(g + (p*t)), (w * p)
	 *p:, stk:(g + (p*t)) - (w * p)
	 */
	void infix_to_postfix(vector <char> &infix, vector <char> &postfix)
	{
		stack <char> stk;

		for (auto &c : infix) {
			if (isdigit(c)) {
				postfix.push_back(c);
			}
			else {
//if there's operators in stack, has priority no lower than curr operator,
//output it from stack to the postfix, then push curr operator to stk (for later process)
				while (!stk.empty() && is_higher_priority_in_stk(c, stk.top())) {
					postfix.push_back(stk.top());
					stk.pop();
				}
				stk.push(c);
			}
		}

		while(!stk.empty()) {
			postfix.push_back(stk.top());
			stk.pop();
		}
	}

	bool is_operator(char c)
	{
		if (c == '*' || c == '+' || c == '-')
			return true;

		return false;
	}

	bool is_higher_priority_in_stk(char curr, char stk_top)
	{
		if (stk_top == '*')
			return true;

		if (curr == '*')
			return false;

		return true;
	}
};


int main(int argc, char **argv)
{
	unordered_map <char, int> var;
	var['g'] = 2;
	var['p'] = 3;
	var['t'] = 1;
	var['w'] = 2;

	vector <vector <char>> expressions = {
		{'g', '+', 'p', '*', 't', '-', 'w', '*', 'p'},
		{'t', '-', 'g', '+', 't', '-', 'w'},
		{'e', '+', 't', '*', 't', '-', 'm'},
	};

	solution s;
	for (auto &e : expressions) {
		int ret = s.calc(e, var);
		for (auto &c : e)
			cout << c << " ";
		cout << " = " << ret << endl;
	}
}
