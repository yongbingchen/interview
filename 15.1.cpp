#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class solution {
	public:
		int reverse(int x)
		{
			//use upper integer type to prevent overflow happen
			long long ret = 0;

			//CAUTION! all + - * / has overflow risk!
			long long operand = x > 0 ? x : (long long)x * -1;
			//long long operand = x > 0 ? x : -x; //THIS IS WRONG FOR INT_MIN CASE

			int sign = x < 0 ? -1 : 1;
			while (operand != 0) {
				ret = ret * 10 + operand % 10;
				operand /= 10;
			}

			if (ret > INT_MAX && sign == 1)
				return 0;

			//CAUTION! correct way to check negative overflow.
			//|INT_MIN| == |INT_MAX + 1|
			//use -INT_MIN, INT_MIN * -1 will itself cause overflow.
			if (ret - 1 > (INT_MAX) && sign == -1)
				return 0;

			return sign * ret;
		}
};

int main(int argc, char **argv)
{
	solution s;

	vector <int> t = {123, -123, INT_MAX, INT_MIN, 100, 1000000003};

	cout << "size of int is " << sizeof(int) << ", size of longlong is " << sizeof(long long) << endl;
	cout << "INT_MIN * -1 will overflow: " << -INT_MIN << endl;
	for (const auto &i : t)
		cout << i << " : " << s.reverse(i) << endl;
}
