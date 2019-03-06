#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class solution {
	public:
		void add_sparse_matrix(unordered_map <string, int> &m1, unordered_map <string, int> &m2, unordered_map <string, int> &result)
		{
			unordered_map <string, bool> used;
			for (auto &i : m2)
				used[i.first] = false;

			for (auto &i : m1) {
				if (m2.find(i.first) != m2.end()) {
					result[i.first] = m1[i.first] + m2[i.first];
					used[i.first] = true;
				}
				else
					result[i.first] = m1[i.first];
			}

			for (auto &i : used) {
				if (!used[i.first])
					result[i.first] = m2[i.first];
			}
		}

		void multiply_sparse_matrix(unordered_map <string, int> &m1, unordered_map <string, int> &m2, unordered_map <string, int> &result)
		{
			unordered_map <string, vector <string>> rows; //use row number as key, store all non-zero elem's col at 'val' vector.
			unordered_map <string, vector <string>> cols; //use col number as key, store all non-zero elem's row at 'val' vector.

			get_all_non_zero_rows(m1, rows);
			get_all_non_zero_cols(m2, cols);

			for (auto &i : rows) {
				for (auto &j : cols) {
					int ret = 0;
					for (auto &k : i.second) {
						string key1 = i.first + "|" + k;
						if (find(j.second.begin(), j.second.end(), k) != j.second.end()) {
							string key2 = k + "|" + j.first;
							if (m1.find(key1) != m1.end() && m2.find(key2) != m2.end())
								ret += m1[key1] * m2[key2];
						}
					}
					if (ret != 0)
						result[i.first + "|" + j.first] = ret;
				}
			}
		}

	private:
		void get_all_non_zero_rows(unordered_map <string, int> &m, unordered_map <string, vector <string>> &rows)
		{
			for (auto &i : m) {
				string row = get_row_num(i.first);
				string col = get_col_num(i.first);
				rows[row].push_back(col);
			}
		}

		void get_all_non_zero_cols(unordered_map <string, int> &m, unordered_map <string, vector <string>> &cols)
		{
			for (auto &i : m) {
				string row = get_row_num(i.first);
				string col = get_col_num(i.first);
				cols[col].push_back(row);
			}
		}

		string get_row_num(string key)
		{
			string delimiter = "|";
			size_t npos = key.find(delimiter);
			return key.substr(0, npos);
		}

		string get_col_num(string key)
		{
			string delimiter = "|";
			size_t npos = key.find(delimiter);
			return key.substr(npos + 1);
		}

};

int main(int argc, char **argv)
{

	unordered_map <string, int> sparse_m1;
	sparse_m1[to_string(1) + "|" + to_string(2)] = 10;
	sparse_m1[to_string(1) + "|" + to_string(4)] = 12;
	sparse_m1[to_string(3) + "|" + to_string(3)] = 5;
	sparse_m1[to_string(4) + "|" + to_string(1)] = 15;
	sparse_m1[to_string(4) + "|" + to_string(2)] = 12;

	unordered_map <string, int> sparse_m2;
	sparse_m2[to_string(1) + "|" + to_string(3)] = 8;
	sparse_m2[to_string(2) + "|" + to_string(4)] = 23;
	sparse_m2[to_string(3) + "|" + to_string(3)] = 9;
	sparse_m2[to_string(4) + "|" + to_string(1)] = 20;
	sparse_m2[to_string(4) + "|" + to_string(2)] = 25;


	solution s;
	cout << "add sparse matrix" << endl;
	unordered_map <string, int> result;
	s.add_sparse_matrix(sparse_m1, sparse_m2, result);
	for (auto &i : result)
		cout << i.first << ", val " << i.second << endl;

	result.clear();
	cout << "multiply sparse matrix" << endl;
	s.multiply_sparse_matrix(sparse_m1, sparse_m2, result);
	for (auto &i : result)
		cout << i.first << ", val " << i.second << endl;


	exit(EXIT_SUCCESS);
}
