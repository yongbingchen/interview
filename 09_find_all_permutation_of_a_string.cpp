#include <iostream>
#include <string>

using namespace std;

class solution {
	public:
		void all_permutation(string s, int start, int len)
		{
			if (start == len - 1) {
				cout << s << endl;
				return;
			}

			//from permutation definition: swap every elem after first elem with it.
			//then get all permutation of the substr after first elem (recursive).
			//'multiply' the first swap result with the second step, we got all result.
			for (int i = start; i < len; i++) { //let 'i' start from 0, so "keep the first elem unchanged" case is also covered.
				swap(s[start], s[i]);
				all_permutation(s, start + 1, len);
				swap(s[start], s[i]); //backtracking is the key to "swap every elem after first elem with it", without this, we will generate same substr after first elem.
			}
		}
};

int main(int argc, char **argv)
{
	string s = "ABC";
	solution t;
	t.all_permutation(s, 0, s.size());
	exit(EXIT_SUCCESS);
}
