#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution {
	public:
		void rotate_image(vector <vector <int>> &a)
		{
			revert_at_45(a);
			turn_over_horizontally(a);
		}
	private:
		void revert_at_45(vector <vector <int>> &a)
		{
			int n = a.size();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n - i; j++) {
					//CAUTION!
					//a[i][j] and b[k][q], their cordinate have below relation:
					// i + q = n; j + k = n
					swap(a[i][j], a[n - 1 - j][n - 1 - i]);
				}
			}
		}
		void turn_over_horizontally(vector <vector <int>> &a)
		{
			int n = a.size();
			for (int i = 0; i < n / 2; i++) {
				for (int j = 0; j < n; j++) {
					swap(a[i][j], a[n - 1 - i][j]);
				}
			}
		}
};

int main(int argc, char **argv)
{
	vector <vector <int>> a = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	solution s;
	s.rotate_image(a);
	for (auto &i : a) {
		for (auto &j : i)
			cout << j << ", ";
		cout << endl;
	}
	exit(EXIT_SUCCESS);
}
