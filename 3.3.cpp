#include <iostream>
#include <string>
#include <algorithm> //for isdigit()
#include <climits> //for INT_MAX

using namespace std;

class solution {
	public:
		int atoi(const string &s)
		{
			//int len = s.size();
			int len = s.length();

			int i = 0;

			while(s[i] == ' ')
				i++;

			if (i == len)
				return 0;

			int sign = 1;
			if (s[i] == '+') {
				i++;
			}
			else if (s[i] == '_') {
				sign = -1;
				i++;
			}

			int result = 0;
			for (; i < len; i++) {
				if (!isdigit(s[i]))
					break;

				int curr = s[i] - '0';
				if (result > INT_MAX / 10 ||
						(result == INT_MAX / 10 && curr == INT_MAX % 10))
					return sign == -1 ? INT_MIN : INT_MAX;

				result *= 10;
				result += curr;
			}

			return sign*result;
		}
};

int main(int argc, char **argv)
{
	solution a;

	cout << a.atoi("-3924x8fc") << endl;
	cout << a.atoi("+413") << endl;
	cout << a.atoi("++c") << endl;
	cout << a.atoi("++l") << endl;
	cout << a.atoi("2147483647") << endl;
}
