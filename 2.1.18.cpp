#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		int climb_stairs(int n)
		{
			if (n == 1 || n == 2) {
				return n;
			}
			vector <int> f(n, 0);
			f[0] = 1;
			f[1] = 2;
			for (int i = 2; i < n; i++) {
				f[i] = f[i - 1] + f[i - 2];
			}
			return f[n - 1];
		}
		int climb_stairs_recursive(int n)
		{
			if (n == 1 || n == 2)
				return n;
			int climbs = climb_stairs(n - 1) + climb_stairs(n - 2);
			//int climbs = climb_stairs(n - 1) + 2 * climb_stairs(n - 2);
			//why do not *2? because from (n - 2) take 1 step will be climb_stairs(n - 1)
			return climbs;
		}

};

int main(int argc, char **argv)
{
	solution a;

	for (int i = 1; i < 11; i++)
		cout << "ways to climb " << i << " steps " << a.climb_stairs(i) << endl;
}
