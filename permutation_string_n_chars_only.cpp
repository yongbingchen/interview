#include <iostream>
#include <vector>

using namespace std;

class solution {
public:
	void permutate_k_group(string input, int idx, int k)
	{
		if (k == idx) {
			cout << input.substr(0, k) << endl;
			return;
		}

		for (int j = idx; j < input.size(); j++) { //!only loop over the elems after idx
			swap(input[idx], input[j]);
			permutate_k_group(input, idx + 1, k);
			swap(input[idx], input[j]);
		}
	}
};

int main(int argc, char **argv)
{
	string input = "redfoxsup";

	solution s;

	s.permutate_k_group(input, 0, 3);
}
