#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class solution {
public:
	int get_result(string input)
	{
		string infix = parse_parenthese(input);
		vector <char> postfix;
		infix_to_postfix(infix, postfix);
		return calc_postfix(postfix);
	}

private:
	/*
	i: 3*(4*5+6) 	p:	 	stk:
	i: *(4*5+6) 	p:3	 	stk:
	i: (4*5+6) 	p:3	 	stk:*
	i: 4*5+6) 	p:3	 	stk:*(
	i:  *5+6) 	p:3,4	 	stk:*(
	i:   5+6) 	p:3,4	 	stk:*(*
	i:   +6) 	p:3,4,5	 	stk:*(*
	i:   +6) 	p:3,4,5,*	stk:*(
	i:   6) 	p:3,4,5,*	stk:*(+
	i:   ) 		p:3,4,5,*,6	stk:*(+
	i:   ) 		p:3,4,5,*,6,+	stk:*(
	i:    		p:3,4,5,*,6,+	stk:*
	i:    		p:3,4,5,*,6,+,*	stk:
	on calc:
	p:3,4,5,*,6,+,*	stk:
	p:*,6,+,*	stk:3,4,5
	p:6,+,*	stk:3,(4*5),
	p:+,*	stk:3,(4*5),6,
	p:*	stk:3,((4*5)+6),
	p:	stk:3*((4*5)+6),
	*/
	void infix_to_postfix(string infix, vector <char> &postfix)
	{
		stack <char> stk;
		for (auto &c : infix) {
			if (isdigit(c)) {
				postfix.push_back(c);
			}
			else if (isoperator(c)) {
				while(!stk.empty() && is_stk_top_higher_priority(c, stk.top())) {
					postfix.push_back(stk.top());
					stk.pop();
				}
				stk.push(c);
			}
			else if (c == '(') {
				stk.push(c);
			}
			else if (c == ')') {
				while(!stk.empty() && stk.top() != '(') {
					postfix.push_back(stk.top());
					stk.pop();
				}
				stk.pop();//drop the '('
			}
		}

		while(!stk.empty()) {
			postfix.push_back(stk.top());
			stk.pop();
		}
	}

	bool isoperator(char c)
	{
		if (c == '*' || c == '+')
			return true;
		return false;
	}

	bool is_stk_top_higher_priority(char curr, char stk_top)
	{
		//!REMEMBER '(' in stack too!
		if (stk_top == '(')
			return false; //!CAUTION, handle '(' as special operator, always keep on pushing stk.
		if (curr == '*')
			return false; //'*' always push stk first
		if (stk_top == '*')
			return true; //if curr is not '*', then need to pop out it first

		return true; //'+' always does not have priority over others ('+' and '*').
	}

	string parse_parenthese(string input)
	{
		string parsed;
		stack <char> stk;
		int num_of_un_matched_parenthese = 0;
		bool is_leading_num;
		bool is_first_parenthese = true;

		for (auto &c : input) {
			if (c == ',')
				continue;
			else if (isdigit(c)) {
				if (is_leading_num) {
					is_leading_num = false;
					stk.push(c);
				}
				else {
					stk.push('+');
					stk.push(c);
				}
			}
			else if (c == '[') {
				is_leading_num = true;
				num_of_un_matched_parenthese++;
				if (!is_first_parenthese) {
					stk.push('+');
				}
				is_first_parenthese = false;
				stk.push('0' + num_of_un_matched_parenthese);
				stk.push('*');
				stk.push('(');
			}
			else if (c == ']') {
				stk.push(')');
			}
			else
				abort();
		}

		while(!stk.empty()) {
			parsed = stk.top() + parsed;
			stk.pop();
		}

		return parsed;
	}

	int calc_postfix(vector <char> &postfix)
	{
		stack <int> calc;
		for (auto &c : postfix) {
			if (isdigit(c))
				calc.push(c - '0');
			else {
				int operand_1 = calc.top();
				calc.pop();
				int operand_2 = calc.top();
				calc.pop();
				if (c == '*')
					calc.push(operand_1 * operand_2);
				else if (c == '+')
					calc.push(operand_1 + operand_2);
			}
		}

		return calc.top();
	}
};


int main(int argc, char **argv)
{
	string input = "[8,3,2,[5,6,[9]],6]";

	solution s;

	int ret = s.get_result(input);
	cout << ret << endl;
}
