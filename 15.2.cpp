#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class solution {
	public:
		bool is_palindrom(int x)
		{
			//can not use reverse(x) then compare with x, because the overflow case.
			x = x < 0 ? (long long)x * -1 : x;

			//compare first digit with last, till all digits compared.
			while (x != 0) {
				int first;
				int last = x % 10;
				long long remain = x;
				int digits = 0;
				while(remain > 0) {
					first = remain % 10;
					digits++;
					remain /= 10;
				}

				if (first != last)
					return false;

				//CAUTION! digits need - 1.
				for (int i = 0; i < digits - 1; i++)
					first *= 10;

				x -= first;
				x /= 10;
			}

			return true;
		}
};

int main(int argc, char **argv)
{
	vector <int> t = {123454321, 12344321, 123, 321, 1, INT_MIN, INT_MAX, 0};

	solution s;

	for (const auto &i : t)
		cout << "is " << i << " a palindrom? " << s.is_palindrom(i) << endl;
}
