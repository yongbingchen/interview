#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution {
	public:
	vector <int> next_permutation(vector <int> &a)
	{
		vector <int> symbol_set = get_symbol_set(a);
		int contor = calc_contor_number(a, symbol_set);

		//calc contor number will remove used from vector, so get it again.
		symbol_set = get_symbol_set(a);
		return get_permutation_by_contor(symbol_set, a.size(), contor + 1);
	}

	private:
		vector <int> get_symbol_set(vector <int> &a)
		{
			vector <int> result = a;
			sort(result.begin(), result.end());
			return result;
		}

		int calc_contor_number(vector <int> &a, vector <int> &symbol_set)
		{
			int contor = 0;
			for (int i = 0; i < a.size(); i++) {
				int base = factorial(a.size() - i - 1);
				//contor number's definition, based on its index in ordered symbol set
				//if symbol was used, then need to remove it.
				int k = get_idx(symbol_set, a[i]);
				contor += k * base;
			}
			return contor;
		}

		vector <int> get_permutation_by_contor(vector <int> symbol_set, int len, int contor)
		{
			vector <int> result;
			int base = factorial(len - 1);

			//for handling next permutation if '321' case.
			contor = contor_mod(symbol_set.size(), len, contor);

			for (int i = len - 1; i >= 0; i--) {
				int idx = contor / base;
				contor %= base;
				if (i != 0)
					base /= i;
				result.push_back(symbol_set[idx]);
				//always remove it after use it.
				symbol_set.erase(symbol_set.begin() + idx);
			}

			return result;
		}

		int factorial(int n)
		{
			int ret = 1;
			for (int i = 1; i <= n; i++)
				ret *= i;
			return ret;
		}

		int contor_mod(int set_size, int len, int contor)
		{
			int max_contor = 0;
			for (int i = len - 1; i >= 0; i--) {
				max_contor += (set_size - 1) * factorial(len - 1);
				set_size--;
				len--;
			}
			//CAUTION! contor number is 0 based, so + 1 before mod.
			return contor % (max_contor + 1);
		}

		int get_idx(vector <int> &symbol_set, int val)
		{
			auto it = find(symbol_set.begin(), symbol_set.end(), val);
			if (it == symbol_set.end())
				return -1;
			int idx = distance(symbol_set.begin(), it);
			symbol_set.erase(it);
			return idx;
		}
};

int main(int argc, char **argv)
{
	vector <vector <int>> t = {
		{1, 2, 3},
		{3, 2, 1},
		{1, 3, 2}
		//{1, 1, 5} sequence with duplicated symbol breaks contor number definition, can not use this method to get its next
	};
	solution s;

	for (auto &i : t) {
		for (auto &j : i)
			cout << j << ", ";
		cout << ": next permutation : ";
		vector <int> ret = s.next_permutation(i);
		for (auto &j : ret)
			cout << j << ", ";
		cout << endl;
	}
}
