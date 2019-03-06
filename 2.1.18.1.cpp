#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		int climb(int n)
		{
			if (n == 0)
				return 0;
			if (n == 1)
				return 1;
			if (n == 2)
				return 2;
			return climb(n -1) + climb(n -2);
		}
};

int main(int argc, char **argv)
{
	solution s;
	for (int i = 0; i < 10; i++)
		cout << "ways to climb " << i << " steps is " << s.climb(i) << endl;
	exit(EXIT_SUCCESS);
}
