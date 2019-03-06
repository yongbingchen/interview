#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		void all_ways(int target, vector <int> &a, int start, vector <int> &result)
		{
			if (target == 0) {
				cout << "find a solution:" << endl;
				for (auto &i : result)
					cout << i << ", ";
				cout << endl;
				return;
			}

			if (start == a.size())
				return;

			int val = a[start];
			all_ways(target, a, start + 1, result);
			result.push_back(val);
			all_ways(target + val, a, start + 1, result);
			result.pop_back(); //backtracking
			result.push_back(-val);
			all_ways(target - val, a, start + 1, result);
			result.pop_back();
		}
};

int main(int argc, char **argv)
{
	solution s;
	int target = 6;
	vector <int> result;
	vector <int> a = {5, 3, -6, 2};

	s.all_ways(target, a, 0, result);
	exit(EXIT_SUCCESS);
}
