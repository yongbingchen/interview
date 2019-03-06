#include <iostream>
#include <vector>

using namespace std;

class solution {
public:
	int total_solutions(vector <int> coeff, int idx, int sum)
	{
		if (sum == 0)
			return 1;

		if (idx == coeff.size())
			return 0;

		if (sum < 0)
			return 0;

		int total_slu = 0;
		int count = sum / coeff[idx];
		for (int i = 0; i <= count; i++) {
			total_slu += total_solutions(coeff, idx + 1, sum - i * coeff[idx]);
		}

		return total_slu;
	}
};

int main(int argc, char **argv)
{
	solution s;
	vector <int> coeff = {1, 3, 5, 7};

	int ret = s.total_solutions(coeff, 0, 8);
	cout << ret << endl;

	exit(EXIT_SUCCESS);
}
