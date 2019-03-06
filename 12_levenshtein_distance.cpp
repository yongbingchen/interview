#include <iostream>
#include <vector>
#include <string>

using namespace std;

class solution {
	public:
		int dist(string a, string b, int len_a, int len_b)
		{
			if (len_a == 0 || len_b == 0)
				return max(len_a, len_b);

			//this is called top down method, try to reduce problem's scale from the largest scale side.
			if (a[len_a - 1] == b[len_b - 1])
				return dist(a, b, len_a - 1, len_b - 1);

			//there're three ways to deal with the last diff char (not necessarily make them the same, just to reduce the scale):
			//a. delete a's last char.
			//b. attach b's last char to a (so they turn to above case, and len_b effectively get minus 1).
			//c. replace a's last char with b's last char, need one op, compared to above case (when the last char are equal)
			return min(min(dist(a, b, len_a - 1, len_b) + 1,
				dist(a, b, len_a, len_b - 1) + 1),
				dist(a, b, len_a - 1, len_b - 1) + 1);
		}
};

int main(int argc, char **argv)
{
	solution s;
	string a = "kitten", b = "sitting";

	int ret = s.dist(a, b, a.size(), b.size());
	cout << ret << endl;

	exit(EXIT_SUCCESS);
}
