#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		int total_path(vector <vector <int>> &phone, int step)
		{
			int ret = 0;
			for (int i = 0; i < phone.size(); i++) {
				for (int j = 0; j < phone[0].size(); j++) {
					if (phone[i][j] >= 0) {
						total_path(phone, i, j, step, ret);
					}
				}
			}
			return ret;
		}
	private:
		void total_path(vector <vector <int>> &phone, int i, int j, int step, int &total)
		{
			if (step == 1) {
				total++;
				return;
			}

			vector <pair <int, int>> next;
			get_all_next(phone, i, j, next);
			for (auto &k : next)
				total_path(phone, k.first, k.second, step - 1, total);
		}

		void get_all_next(vector <vector <int>> &phone, int i, int j, vector <pair <int, int>> &next)
		{
			vector <pair <int, int>> all_dirs = {
				pair <int, int>(i + 1, j + 1),
				pair <int, int>(i + 1, j - 1),
				pair <int, int>(i - 1, j + 1),
				pair <int, int>(i - 1, j - 1),
				pair <int, int>(i + 0, j + 2),
				pair <int, int>(i + 0, j - 2),
				pair <int, int>(i + 2, j + 0),
				pair <int, int>(i - 2, j + 0),
			};

			for (auto &k : all_dirs) {
				if (is_inside(phone, k.first, k.second)) {
					if (is_inside(phone, k.first + 1, k.second)) {
						next.push_back(pair <int, int>(k.first + 1, k.second));
						cout << "for num " << phone[i][j] << ", found next num " << phone[k.first + 1][k.second] << endl;
					}
					if (is_inside(phone, k.first - 1, k.second)) {
						next.push_back(pair <int, int>(k.first - 1, k.second));
						cout << "for num " << phone[i][j] << ", found next num " << phone[k.first - 1][k.second] << endl;
					}
				}
			}
		}

		bool is_inside(vector <vector <int>> &phone, int i, int j)
		{
			if (i < 0 || j < 0 || i > phone.size() - 1 || j > phone[0].size() - 1)
				return false;
			if (phone[i][j] < 0)
				return false;
			return true;
		}
};

int main(int argc, char **argv)
{
	vector <vector <int>> phone = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
		{-1, 0, -1},
	};
	solution s;

	for (int step = 1; step < 3; step++) {
		int ret = s.total_path(phone, step);
		cout << "step " << step << ", total path " << ret << endl;
	}

	exit(EXIT_SUCCESS);
}
