#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		bool search_2d_matrix(const vector <vector <int>> &matrix, const int target)
		{
			auto rows = matrix.size();
			auto columns = matrix[0].size();

			int begin = 0;
			int end  = rows * columns;

			while(begin < end) {
				int mid = begin + (end - begin) / 2;
				int i = mid / columns;
				int j = mid % columns;

				if (matrix[i][j] == target)
					return true;
				else if (matrix[i][j] < target)
					begin = mid + 1;
				else
					end = mid;
			}

			return false;
		}
};

int main(int argc, char **argv)
{
	vector <vector <int>> matrix = {
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 50}
	};

	solution s;

	cout << s.search_2d_matrix(matrix, 3) << endl;
}
