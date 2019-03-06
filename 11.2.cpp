#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class solution {
	public:
		int my_sqrt(int x)
		{
			if (x < 0)
				return INT_MIN;

			if (x < 4)
				return 1;

			int start = 1; // sqrt(x) must be > 1;
			int end = x / 2; //when x > 2, sqrt(x) must be > x / 2
			int mid;

			while(start < end) {
				mid = start + (end - start) / 2;
				if (x / mid < mid) {
					end  = mid - 1;
				}
				else if (x / mid > mid) {
					start = mid + 1;
				}
				else {
					return mid; //this can be true.
				}
			}

			return mid;
		}
};

int main(int argc, char**argv)
{
	solution s;
	vector <int> t = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 25, 78, 100, 1000, 10000, 1000000};

	for (const auto &i : t)
		cout << "sqrt " << i << " is " << s.my_sqrt(i) << endl;
}
