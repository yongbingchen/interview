#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class solution {
	public:
		int longest_alter_subseq(vector <int> &a, int idx, int prev, bool bigger)
		{
			if (idx == 0) {
				if (bigger && a[0] > prev)
					return 1;
				if (!bigger && a[0] < prev)
					return 1;
				return INT_MIN;
			}
			int with_curr = INT_MIN;
			//add this condition before include curr node, KEY point to get correct result.
			if (bigger && a[idx] > prev || !bigger && a[idx] < prev)
				with_curr = longest_alter_subseq(a, idx - 1, a[idx], !bigger) + 1;
			int wo_curr = longest_alter_subseq(a, idx - 1, prev, bigger);
			return max(with_curr, wo_curr);
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <int> a = {8, 9, 6, 4, 5, 7, 3, 2, 4};

	int longest = 0;
	int end_bigger = s.longest_alter_subseq(a, a.size() - 2,  a[a.size() - 1], false);
	int end_less = s.longest_alter_subseq(a, a.size() - 2,  a[a.size() - 1], true);
	longest = max(end_less, end_bigger) + 1;
	cout << longest << endl;
	exit(EXIT_SUCCESS);
}
