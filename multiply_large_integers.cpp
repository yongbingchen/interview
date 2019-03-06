#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution {
	public:
		string multiply(string f1, string f2)
		{
			string result;
			for (int i = f2.size() - 1; i >= 0; i--) {
				string curr = multiply(f1, f2[i]);
				for (int j = 0; j < f2.size() - 1 - i; j++)
					curr.push_back('0');
				result = add_result(result, curr);
			}
			return result;
		}
	private:
		string multiply(string f1, char c)
		{
			string ret;
			int carry = 0;

			for (int i = f1.size() - 1; i >= 0; i--) {
				int bit = (f1[i] - '0') * (c - '0') + carry;
				carry = bit / 10;
				ret.push_back('0' + (bit % 10));
			}

			if (carry != 0)
				ret.push_back('0' + carry);

			reverse(ret.begin(), ret.end());
			return ret;
		}

		string add_result(string s1, string s2)
		{
			string ret;
			int carry = 0;

			for (int i = s1.size() - 1, j = s2.size() - 1; i >= 0 || j >= 0; i--, j--) {
				int c1 = i >= 0 ? s1[i] - '0' : 0;
				int c2 = j >= 0 ? s2[j] - '0' : 0;
				int bit = c1 + c2 + carry;
				carry = bit / 10;
				ret.push_back('0' + (bit % 10));
			}

			if (carry != 0)
				ret.push_back('0' + carry);

			reverse(ret.begin(), ret.end());
			return ret;
		}
};

int main(int argc, char **argv)
{
	string f1 = "123456789123456789";
	string f2 = "777788888888777799";
	solution s;
	string result = s.multiply(f1, f2);
	cout << result << endl;
	exit(EXIT_SUCCESS);
}
