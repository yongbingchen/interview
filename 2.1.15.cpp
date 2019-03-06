#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		int trapping_water(vector <int>&a)
		{
			int n = a.size();
			int ret = 0;
			for (int i = 0; i < n; i++) {
				int left = 0;
				int right = 0;
				for (int j = i + 1; j < n; j++) {
					right = max(right, a[j]);
				}
				for (int j = i - 1; j > 0; j--) {
					left = max(left, a[j]);
				}

				int this_trap = min(right, left);
				this_trap = this_trap > a[i] ? this_trap - a[i] : 0;
				ret += this_trap;
			}
			return ret;
		}
};

int main(int argc, char **argv)
{
	vector <int> a = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

	solution s;
	cout << "trapping rain water " << s.trapping_water(a) << endl;
	exit(EXIT_SUCCESS);
}
