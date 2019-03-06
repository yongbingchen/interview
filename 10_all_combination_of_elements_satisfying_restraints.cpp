#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		void all_combination(int elem, vector <int> &result)
		{
			if (elem == 0) {
				for (auto &i: result)
					cout << i << ", ";
				cout << endl;
				return;
			}
			//try put curr elem at every possible place.
			for (int i = 0; i + elem + 1 <= result.size() - 1; i++) { // <= i s the key to include all possible place.
				if (result[i] == -1 && result[i + elem + 1] == -1) {
					result[i] = elem;
					result[i + elem + 1] = elem;
					all_combination(elem - 1, result);
					result[i] = -1;
					result[i + elem + 1] = -1;
				}
			}
		}
};

int main(int argc, char **argv)
{
	solution s;
	int n = 3;
	vector <int> result(n * 2, -1);
	s.all_combination(n, result);
	exit(EXIT_SUCCESS);
}
