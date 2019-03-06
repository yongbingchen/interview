#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		int remove_duplicate(vector <int> &array)
		{
			int len = array.size();
			if (len == 0)
				return 0;

			int idx = 0;
			for (int i = 1; i < len; i++) {
				if (array[idx] != array[i]) {
					idx++;
					array[idx] = array[i];
				}
			}

			return idx + 1;
		}
};

int main(int argc, char **argv)
{
	vector <vector <int>> test = {
		{1, 2, 2, 3},
		{1, 1, 2, 3, 3, 3, 3, 3, 3},
		{1, 1, 1, 1, 1}
	};

	solution s;

	for (auto &i : test) {
		int ret = s.remove_duplicate(i);
		cout << "new length is " << ret << endl;
		//for (const auto &j : i) WRONG! the original content of duplicates still there
		for (int j = 0; j < ret; j++)
			cout << i[j] << ", ";
		cout << endl;
	}
}

