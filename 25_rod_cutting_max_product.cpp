#include <iostream>

using namespace std;

class solution {
public:
	int max_product(int idx, int len)
	{
		//DO not return 0!, because it's a multiply factor, not add!
		if (idx <= 0)
			return 1;
		if (len <= 0)
			return 1;

		int total_cut = len / idx;
		int max_p = 0;
		for (int i = 0; i < total_cut + 1; i++) {
			int tmp = max_product(idx - 1, len - i * idx);
			for (int j = 0; j < i; j++)
				tmp *= idx;

			max_p = max(max_p, tmp);
		}

		return max_p;
	}
};

int main(int argc, char **argv)
{
	solution s;

	for (int i = 4; i < 16; i++) {
		int ret = s.max_product(i, i);
		cout << "for len " << i << ", max cut rod product is " << ret << endl;
	}
	exit(EXIT_SUCCESS);
}
