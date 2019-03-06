#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class solution {
	public:
		void min_swap(string input, string &curr_min, int k)
		{
			if (k == 0) {
				if (curr_min.compare(input) > 0)
					curr_min = input;
				return;
			}

			//for every elem in input, compare it with all other elem behind it (this is enough to cover all possible combination of pair in the input).
			for (int i = 0; i < input.size(); i++) {
				for (int j = i + 1; j < input.size(); j++) {
					swap(input[i], input[j]);
					min_swap(input, curr_min, k - 1);
					swap(input[i], input[j]);
				}
			}
		}
};

int main(int argc, char **argv)
{
	solution s;
	string input = "934651";
	for (int k = 1; k < 4; k++) {
		string output = input;
		s.min_swap(input, output, k);
		cout << "for input " << input << ", swap " << k << " times, minimum output is " << output << endl;
	}

	exit(EXIT_SUCCESS);
}

