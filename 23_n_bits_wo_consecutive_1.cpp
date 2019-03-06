#include <iostream>
#include <vector>
#include <string>

using namespace std;

class solution {
	public:
		void get_strs_wo_consecutive_1(vector <string> &result, int bits)
		{
			if (bits == 0)
				return;

			int existing = result.size();
			for (int i = 0; i < existing; i++) {
				if (result[i][0] == '0') {
					result.push_back('1' + result[i]);
				}

				result[i] = '0' + result[i];
			}

#if 0 //ERROR! can not use iterator over a container, while add/remove element
			in the loop, will invalidate the iterator, causing
				segementation fault.
			for (auto &s : result) {
				if (s[0] == '0') {
					result.push_back('1' + s);
				}

				s = "0" + s;
			}
#endif

			get_strs_wo_consecutive_1(result, bits - 1);
		}

		void get_strs_wo_consecutive_one(vector <string> &result, int bits)
		{
			if (bits == 0)
				return;
			result.push_back("0");
			result.push_back("1");

			for (int i = 1; i < bits; i++) {
				int existing = result.size();
				for (int j = 0; j < existing; j++) {
					if (result[j][0] == '0') {
						result.push_back('1' + result[j]);
					}

					result[j] = '0' + result[j];
				}
			}
		}

};

int main(int argc, char **argv)
{
	solution s;
	vector <string> result;
	s.get_strs_wo_consecutive_one(result, 5);
	for (auto &i :  result)
		cout << i << endl;


	cout << "try recursive way" << endl;
	result.clear();
	result.push_back("0");
	result.push_back("1");
	s.get_strs_wo_consecutive_1(result, 5 - 1);
	for (auto &i :  result)
		cout << i << endl;

	exit(EXIT_SUCCESS);
}
