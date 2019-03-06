#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		int single_num(vector <int> &array)
		{
			int x = 0;

			for (auto &a : array) {
				x = a ^ x;
			}

			return x;
		}
};

int main(int argc, char **argv)
{
	solution a;
	vector <int> array = {1, 1, 2, 2, 3, 3, 2, 2, 4};

	cout << "single num is " << a.single_num(array) << endl;
}
