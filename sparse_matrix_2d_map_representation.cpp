#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef unordered_map <int, unordered_map <int, int>> two_d_matrix;
typedef unordered_map <int, unordered_map <int, bool>> two_d_flag;

class solution {
	public:
		void add_sparse_matrix(two_d_matrix &m1, two_d_matrix &m2, two_d_matrix &result)
		{
			two_d_flag used;
			for (auto &i : m2)
				for (auto &j : i.second) //!WARNING, it's not for (auto &j : i)
					used[i.first][j.first] = false;

			for (auto &i : m1)
				for (auto &j : i.second) {
					if (m2.find(i.first) != m2.end() &&
							m2[i.first].find(j.first) != m2[i.first].end()) {
						result[i.first][j.first] = m1[i.first][j.first] + m2[i.first][j.first];
						used[i.first][j.first] = true;
					}
					else
						result[i.first][j.first] = m1[i.first][j.first];
				}

			for (auto &i : used)
				for (auto &j : i.second) {
					if (!used[i.first][j.first])
						result[i.first][j.first] = m2[i.first][j.first];
				}
		}

		void multiply_sparse_matrix(two_d_matrix &m1, two_d_matrix &m2, two_d_matrix &result)
		{
			unordered_map <int, vector <int>> rows; //use row number as key, store all non-zero elem's col at 'val' vector.
			unordered_map <int, vector <int>> cols; //use col number as key, store all non-zero elem's row at 'val' vector.

			get_all_non_zero_rows(m1, rows);
			get_all_non_zero_cols(m2, cols);

			for (auto &i : rows) {
				for (auto &j : cols) {
					int ret = 0;
					for (auto &k : i.second) {
						if (find(j.second.begin(), j.second.end(), k) != j.second.end())
							ret += m1[i.first][k] * m2[k][j.first]; //write down a real dot multiply to figure out this equation.
					}
					if (ret != 0)
						result[i.first][j.first] = ret;
				}
			}
		}

	private:
		void get_all_non_zero_rows(two_d_matrix &m, unordered_map <int, vector <int>> &rows)
		{
			for (auto &i : m)
				for (auto &j : i.second)
					rows[i.first].push_back(j.first);
		}

		void get_all_non_zero_cols(two_d_matrix &m, unordered_map <int, vector <int>> &cols)
		{
			for (auto &i : m)
				for (auto &j : i.second)
					cols[j.first].push_back(i.first);
		}


};

int main(int argc, char **argv)
{
	two_d_matrix sparse_m1;
	sparse_m1[1][2] = 10;
	sparse_m1[1][4] = 12;
	sparse_m1[3][3] = 5;
	sparse_m1[4][1] = 15;
	sparse_m1[4][2] = 12;

	two_d_matrix sparse_m2;
	sparse_m2[1][3] = 8;
	sparse_m2[2][4] = 23;
	sparse_m2[3][3] = 9;
	sparse_m2[4][1] = 20;
	sparse_m2[4][2] = 25;


	solution s;
	cout << "add sparse matrix" << endl;
	two_d_matrix result;
	s.add_sparse_matrix(sparse_m1, sparse_m2, result);
	for (auto &i : result)
		for (auto &j : i.second)
			cout << i.first << ", " << j. first << ", val " << result[i.first][j.first] << endl;

	result.clear();
	cout << "multiply sparse matrix" << endl;
	s.multiply_sparse_matrix(sparse_m1, sparse_m2, result);
	for (auto &i : result)
		for (auto &j : i.second)
			cout << i.first << ", " << j. first << ", val " << result[i.first][j.first] << endl;

	exit(EXIT_SUCCESS);
}
