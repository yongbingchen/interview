#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class solution {
public:
	int find_pair(vector <int> &a, int k)
	{
		unordered_map <int, int> map;

		sort(a.begin(), a.end());
		int ret = 0;
		for (auto &i : a) {
			if (map.find(i) != map.end())
				ret += map[i];

			vector <int> b;
			get_all_b(i, k, b);
			for (auto &j : b) {
				map[j] += 1;
			}
		}

		return ret;
	}

private:
	void get_all_b(int a, int k, vector <int> &b)
	{
		vector <int> zero;

		for (int i = 0; i < k; i++) {
			if ((a & (0x1 << i)) == 0) {
				zero.push_back(i);
			}
		}

		for (auto &i : zero) {
			for (auto &j : b) {
				b.push_back(j | 0x1 << i);
			}
			b.push_back(a | 0x1 << i);
		}
	}
};

int main(int argc, char **argv)
{
	vector <vector <int>> test_vectors = {
		{0b111, 0b101, 0b010},
		{0b110, 0b011, 0b101},
	};

	solution s;
	for (auto &a : test_vectors)
		cout << "pair of bits satisfy (a < b) && (a & b == a) " << s.find_pair(a, 3) << endl;
}
