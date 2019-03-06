#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		void plus_one(vector <int> &a)
		{
			int carry = 1;
			for (auto it = a.rbegin(); it != a.rend(); it++) {
				int digit = *it + carry;
				carry = digit / 10;
				digit %= 10;
				*it = digit;
			}

			if (carry != 0)
				a.insert(a.begin(), 1);
		}
};

int main(int argc, char **argv)
{
	vector <int> digits = { 9, 9, 9, 9};

	solution a;

	a.plus_one(digits);

	for (auto &i : digits)
		cout << i;
	cout <<endl;

	exit(EXIT_SUCCESS);
}
