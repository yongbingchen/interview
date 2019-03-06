#include <iostream>

using namespace std;

class solution {
	public:
		double my_pow(double base, int expo)
		{
			if (expo < 0)
				return 1.0 / power(base, -expo);

			return power(base, expo);
		}
	private:
		double power(double base, int n)
		{
			if (n == 0)
				return 1;

			//CAUTION! this is special.
			if (n == 1)
				return base;

			double v = power(base, n / 2);

			double result = v * v;

			if (n % 2 == 1)
				result *= base;

			return result;
		}
};

int main(int argc, char **argv)
{
	double base = 1.0359;
	solution s;

	cout << base << "^10 = " << s.my_pow(base, 10) <<endl;
}
