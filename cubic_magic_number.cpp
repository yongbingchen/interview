#include <iostream>
#include <vector>

using namespace std;

class solution {
public:
	void find_magic_number(vector <int> &result)
	{
		vector <int> cube = {0, 1, 8, 27, 64, 125, 216, 342, 512, 729};

		int max_num = 0;
		for (auto &i : cube)
			max_num += i;

		for (int i = 0; i <= max_num; i++) {
			vector <int> all_digits;
			get_all_digits(i, all_digits);
			if (is_match(i, cube, all_digits))
				result.push_back(i);
		}
	}
private:
	void get_all_digits(int i, vector <int> &digits)
	{
		do {
			int digit = i % 10;
			digits.push_back(digit);
			i /= 10;
		} while(i > 0);
	}

	bool is_match(int i, vector <int> &cube, vector <int> &digits)
	{
		int add = 0;
		for (auto &c : digits)
			add += cube[c];

		return add == i;
	}
};

int main(int argc, char **argv)
{

	vector <int> result;
	solution s;
	s.find_magic_number(result);
	for (auto &i : result)
		cout << i << ", ";
	cout <<endl;
}
