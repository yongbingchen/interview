#include <iostream>
#include <vector>

using namespace std;

class solution {
public:
	int largest_plus(vector <vector <int>> &matrix, int &center)
	{
		int ret = 0;

		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				vector <int> curr;
				if (matrix[i][j] == 1) {
					int t = plus_1s(matrix, i, j);
					if (t > ret) {
						ret = t;
						center = i * matrix[0].size() + j;
					}
				}
			}
		}

		return ret;
	}
private:
	int plus_1s(vector <vector <int>> &matrix, int i, int j)
	{
		int count = 1;

		while ((j - count >= 0 && matrix[i][j - count] == 1) &&
				(j + count < matrix[0].size() && matrix[i][j + count] == 1) &&
				(i - count >= 0 && matrix[i - count][j] == 1) &&
				(i + count < matrix.size() && matrix[i + count][j] == 1))
			count++;

		return count;
	}
};

int main(int argc, char **argv)
{
	solution s;
	vector <vector <int>> matrix = {
		{1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
		{1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
		{1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
		{0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
		{1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
		{1, 0, 0, 0, 1, 0, 0, 1, 0, 1},
		{1, 0, 1, 1, 1, 1, 0, 0, 1, 1},
		{1, 1, 0, 0, 1, 0, 1, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 0, 1, 0, 0}
	};

	int center;
	int ret = s.largest_plus(matrix, center);
	cout << "largest plus 1s in the matrix is " << (ret - 1) * 4 + 1 << ", centered at (" << center / matrix[0].size() << ", " << center % matrix[0].size() << ")" << endl;

	exit(EXIT_SUCCESS);
}
