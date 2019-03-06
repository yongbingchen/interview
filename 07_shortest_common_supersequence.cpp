#include <iostream>
#include <string>

using namespace std;

class solution {
	public:
		int shortest_common_superseq(string a, string b, int len_a, int len_b)
		{
			if (len_a == 0 || len_b == 0)
				return len_a + len_b; //diff 1

			if (a[len_a - 1] == b[len_b - 1])
				return shortest_common_superseq(a, b, len_a - 1, len_b - 1) + 1;

			return min/*diff 3*/(shortest_common_superseq(a, b, len_a - 1, len_b) + 1, //diff 2
					shortest_common_superseq(a, b, len_a, len_b - 1) + 1);
		}
};

int main(int argc, char **argv)
{
	solution s;
	string a = "ABCBDBA", b = "BDCABA";

	cout << "shortest common super sequence of " << a << " and " << b << " is " << s.shortest_common_superseq(a, b, a.size(), b.size()) << endl;
	exit(EXIT_SUCCESS);
}
