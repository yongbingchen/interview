#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class solution {
	public:
		int optm_matrix_multp(vector <vector <int>> &dims, int start, int end)
		{
			//no cost if only one matrix
			if (start == end)
				return 0;

			int min_cost = INT_MAX;
			for (int k = start; k < end; k++) {
				//cost of multiplication from M(start) to M(k), the result is
				//a M[start.row][k.col] matrix.
				int left = optm_matrix_multp(dims, start, k);


				//cost of multiplication from M(k + 1) to M(end), the result is
				//a M[k + 1.row][end.col] matrix, while k + 1.row == k.col, so
				//the result is actually a M[k.col][end.col].
				int right = optm_matrix_multp(dims, k + 1, end);

				//the cost of M[start.row][k.col] *  M[k.col][end.col];
				int left_right = dims[start][0] * dims[k][1] * dims[end][1];
				int cost = left + right + left_right;
				cout << "calculating cost for multiply from " << start << " to " << end << endl;
				cout << "cost of multiply from " << start << " to " << k << " is " << left << endl;
				cout << "cost of multiply from " << k << " to " << end << " is " << right << endl;
				cout << "when divide matrices form " << k << "th, the cost of multiply the result of front half " << start << ", " << k;
				cout << " and back half " << k << ", " << end << " is " << left_right << endl;
				cout << "total cost is " << cost << endl;

				min_cost = min(cost, min_cost);
			}

			return min_cost;
		}
};

int main(int argc, char **argv)
{
	solution s;
	//this represents matrix M1(10x30), M2(30x5), M3(5x60)
	//two possible way to do M1 x M2 x M3
	//M1 x (M2 x M3): M2 x M3 takes 5 multiplication to get one point of
	//result (M4(30x60), (ignore the sum op),so 5*30*60, then M1xM4 takes 30*10*60, two
	//steps takes 5*30*60 + 30*10*60 = 27000 in total.
	//while the second way (M1 x M2) x M3: 30*10*5 + 5*10*60 = 4500 in total
	vector <vector <int>> dims = {{10, 30}, {30, 5}, {5, 60}};

	int result = s.optm_matrix_multp(dims, 0, dims.size() - 1);
	cout << result << endl;
	exit(EXIT_SUCCESS);
}
