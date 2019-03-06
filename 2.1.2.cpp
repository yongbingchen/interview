#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
	int remove_dup(vector <int> &a)
	{
		int len = a.size();
		if (len < 2)
			return len;

		int idx = 1;
		//KEY point is start from third node.
		for (int i = 2; i < len; i++) {
			//only take care of already 2 equal nodes in result:
			if (a[idx] == a[idx - 1]) {
				if (a[idx] != a[i]) {
					a[++idx] = a[i];
				}
			}
			else
				a[++idx] = a[i];
		}

		return idx + 1;
	}
};

int main(int argc, char **argv)
{
	vector <vector <int>> test = {
		{1, 2, 2},
		{1, 2, 3},
		{1, 2, 2, 3},
		{1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3},
		{1, 1, 1, 2, 2, 3, 3},
		{1, 1, 2, 2, 3, 3, 4, 4},
	};

	solution s;
	for (auto &i : test) {
		int ret = s.remove_dup(i);
		cout << "removed array length " << ret << endl;
		for ( int j = 0; j < ret; j++)
			cout << i[j] << ", ";
		cout << endl;
	}

	exit(EXIT_SUCCESS);
}
