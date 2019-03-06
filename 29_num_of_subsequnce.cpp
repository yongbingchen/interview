#include <iostream>
#include <vector>
#include <string>

using namespace std;

class solution {
	public:
		int num_of_subseq(string s, string p, int len_s, int len_p)
		{
			if (len_s == 1 && len_p == 1)
				return s[0] == p[0];
			if (len_p == 0)
				return 1;
			if (len_s < len_p)
				return 0;

			int ret = 0;
			//if last char matches, we NEED to search sub pattern in remaining src string.
			if (s[len_s - 1] == p[len_p - 1])
				ret = num_of_subseq(s, p, len_s - 1, len_p - 1);
			//HARD part, no matter last char match or not, we can still pass last char in src string, keep on search the full patter without this last char in src string.
			ret += num_of_subseq(s, p, len_s - 1, len_p);
			return ret;
		}
};

int main(int argc, char **argv)
{
	string s = "subsequence";
	string p = "sue";

	solution su;
	int ret = su.num_of_subseq(s, p, s.size(), p.size());
	cout << ret << endl;

	exit(EXIT_SUCCESS);
}
