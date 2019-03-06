#include <iostream>
#include <string>

using namespace std;

class solution {
	public:
		int longest_palindrom_subseq(string a, int start, int end)
		{
			if (start > end)
				return 0;

			if (start == end)
				return 1;

			if (a[start] == a[end])
				return longest_palindrom_subseq(a, start + 1, end - 1) + 2;


			return max(longest_palindrom_subseq(a, start + 1, end),
					longest_palindrom_subseq(a, start, end - 1));

		}

};

int main(int argc, char **argv)
{
	solution s;
	string a = "ABBDCACB";

	cout << "the length of longest palindrom sub sequnce of " << a << " is " << s.longest_palindrom_subseq(a, 0, a.size() - 1) << endl;

	exit(EXIT_SUCCESS);
}
