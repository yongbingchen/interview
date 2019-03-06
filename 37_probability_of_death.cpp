#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		void calc_total_path(int rows, int cols, int i,  int j, int steps, int &death, int &alive)
		{
			if (i >= rows || j >= cols || i < 0 || j < 0) {
				death++;
				return;
			}
			if (steps == 0) {
				alive++;
				return;
			}

			calc_total_path(rows, cols, i - 1, j, steps - 1, death, alive);
			calc_total_path(rows, cols, i, j - 1, steps - 1, death, alive);
			calc_total_path(rows, cols, i + 1, j, steps - 1, death, alive);
			calc_total_path(rows, cols, i, j + 1, steps - 1, death, alive);
		}
};

int main(int argc, char **argv)
{
	solution s;
	for (int i = 2; i < 5; i++) {
		for (int steps = 1; steps < i; steps++) {
			int alive = 0, death = 0;
			s.calc_total_path(i ,i, 0, 1, steps, death, alive);
			cout << "for matrix with row/col " << i << ", form (0, 1), take " << steps << " steps, alive is " << alive << ", death is " << death << endl;
		}
	}

	exit(EXIT_SUCCESS);
}
