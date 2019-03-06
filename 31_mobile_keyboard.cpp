#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		int total_combination(vector <vector <char>> &keyboard, int i, int j, int digits)
		{
			if (i < 0 || j < 0 || i > keyboard.size() - 1 || j > keyboard[0].size() - 1)
				return 0;

			if (keyboard[i][j] == '*' || keyboard[i][j] == '#')
				return 0;
			if (digits == 0)
				return 0;
			if (digits == 1)
				return 1;


			int total = total_combination(keyboard, i, j, digits - 1); //repeat self
			total += total_combination(keyboard, i + 1, j, digits - 1); //up
			total += total_combination(keyboard, i, j + 1, digits - 1); //right
			total += total_combination(keyboard, i - 1, j, digits - 1); //down
			total += total_combination(keyboard, i, j - 1, digits - 1); //left

			return total;
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <vector <char>> keyboard = {
		{'1', '2', '3'},
		{'4', '5', '6'},
		{'7', '8', '9'},
		{'*', '0', '#'},
	};

	for (int digits = 1; digits < 4; digits++) {
		int total_combination = 0;
		for (int i = 0; i < keyboard.size(); i++)
			for (int j = 0; j < keyboard[0].size(); j++)
				total_combination += s.total_combination(keyboard, i, j, digits);
		cout << "for digits " << digits << ", total combination is " << total_combination << endl;
	}

	exit(EXIT_SUCCESS);
}
