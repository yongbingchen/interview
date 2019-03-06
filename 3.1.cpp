#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class solution {
	public:
		bool is_valid(string s)
		{
			transform(s.begin(), s.end(), s.begin(), ::tolower);

			int len = s.size();
			int front = 0;
			int back = len - 1;
			while(front < back) {
				while (!isalnum(s[front]))
					front++;
				while (!isalnum(s[back]))
					back--;

				if (s[front] != s[back])
					return false;

				front++;
				back--;
			}
			return true;
		}
};

int main(int argc, char**argv)
{
	solution a;
	string s = "A man, a plan, a canal: Panama";

	cout << "is a valid palindrome " << a.is_valid(s) << endl;

	s = "race a car";
	cout << "is a valid palindrome " << a.is_valid(s) << endl;
}
