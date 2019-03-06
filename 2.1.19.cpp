#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		vector <int> gray_code(int n)
		{
			vector <int> result;
			int total = 1 << n;
			for (int i = 0; i < total; i++) {
				//! gray code fromula using 'i >> 1', but node preceeding code itself.
				int code = i ^ (i >> 1);
				result.push_back(code);
			}
			return result;
		}
};

int main(int argc, char **argv)
{
	solution s;
	for (int i = 2; i < 6; i++) {
		cout << "for number " << i << ", its gray code set is:" << endl;
		vector <int> ret = s.gray_code(i);
		for (auto &j : ret)
			cout << j << ", ";
		cout << endl;
	}
	exit(EXIT_SUCCESS);
}
