#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		int max_coins(vector <int> &a, int start, int end)
		{
			if (start == end)
				return a[start];
			if (start + 1 == end)
				return max(a[start], a[end]);


			int pick_left = a[start] + min(max_coins(a, start + 1, end - 1), max_coins(a, start + 2, end));
			int pick_right = a[end] + min(max_coins(a, start, end - 2), max_coins(a, start + 1, end - 1));

			return max(pick_left, pick_right);
		}
};

int main(int argc, char **argv)
{
	vector <vector <int>> test = {
		{4, 6, 2, 3},
		{6, 1, 4, 9, 8, 5},
	};

	solution s;
	for (auto &i : test) {
		int ret = s.max_coins(i, 0, i.size() - 1);
		cout << "max coin is " << ret << endl;
	}

	exit(EXIT_SUCCESS);
}
