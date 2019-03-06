#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		int single_one(vector <int> &a)
		{
			int bits = sizeof(int) * 8;
			vector <int> bit_sum(bits, 0);

			for (int i = 0; i < a.size(); i++) {
				for (int j = 0; j < bits; j++) {
					bit_sum[j] += (a[i] >> j) & 0x1;
					//this mod operation will remove all numbers showed three times.
					bit_sum[j] %= 3;
				}
			}
			int result = 0;
			for (int i = 0; i < bits; i++)
				result += bit_sum[i] << i;

			return result;
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <int> array = {1, 2, 3, 1, 2, 3, 1, 2, 3, 4};

	cout << "single num is " << s.single_one(array) << endl;

	exit(EXIT_SUCCESS);
}
