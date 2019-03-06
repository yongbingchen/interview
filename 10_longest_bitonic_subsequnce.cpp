#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution {
	public:
		vector <int> longest_bitonic_subseq(vector <int> &a)
		{
			vector <vector <int>> lis(a.size());
			vector <vector <int>> rlis(a.size());
			lis[0].push_back(a[0]);
			for (int i = 1; i < a.size(); i++) {
				for (int j = 0; j < i; j++) {
					if (a[i] > a[j] && lis[i] < lis[j])
						lis[i] = lis[j];
				}
				lis[i].push_back(a[i]);
			}

			rlis[a.size() - 1].push_back(a[a.size() - 1]);
			for (int i = a.size() - 2; i >= 0; i--) {
				for (int j = a.size() - 1; j > i; j--) {
					if (a[i] > a[j] && rlis[i] < rlis[j])
						rlis[i] = rlis[j];
				}
				rlis[i].push_back(a[i]);
			}

			int max_idx = 0;
			for (int i = 0; i < a.size(); i++) {
				if (lis[i].size() + rlis[i].size() > lis[max_idx].size() + rlis[max_idx].size())
					max_idx = i;
			}

			lis[max_idx].insert(lis[max_idx].end(), next(rlis[max_idx].rbegin()), rlis[max_idx].rend());

			return lis[max_idx];
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <int> a = {4, 2, 5, 9, 7, 6, 10, 3, 1};
	vector <int> result = s.longest_bitonic_subseq(a);

	for (auto &i : result)
		cout << i << ", ";
	cout << endl;

	exit(EXIT_SUCCESS);
}
/*
for sub array 4,2, the increase sub sequence which end with curr elem 2 is: 2,
for sub array 4,2,5, the increase sub sequence which end with curr elem 5 is: 4,5,
for sub array 4,2,5,9, the increase sub sequence which end with curr elem 9 is: 4,5,9,
for sub array 4,2,5,9,7, the increase sub sequence which end with curr elem 7 is: 4,5,7,
for sub array 4,2,5,9,7,6, the increase sub sequence which end with curr elem 6 is: 4,5,6,
for sub array 4,2,5,9,7,6,10, the increase sub sequence which end with curr elem 10 is: 4,5,9,10,
for sub array 4,2,5,9,7,6,10,3, the increase sub sequence which end with curr elem 3 is: 2,3,
for sub array 4,2,5,9,7,6,10,3,1, the increase sub sequence which end with curr elem 1 is: 1,
for sub array 1, the decrease sub sequence which start with curr elem 1 is: 1,
for sub array 3,1, the decrease sub sequence which start with curr elem 3 is: 1,3,
for sub array 10,3,1, the decrease sub sequence which start with curr elem 10 is: 1,3,10,
for sub array 6,10,3,1, the decrease sub sequence which start with curr elem 6 is: 1,3,6,
for sub array 7,6,10,3,1, the decrease sub sequence which start with curr elem 7 is: 1,3,6,7,
for sub array 9,7,6,10,3,1, the decrease sub sequence which start with curr elem 9 is: 1,3,6,7,9,
for sub array 5,9,7,6,10,3,1, the decrease sub sequence which start with curr elem 5 is: 1,3,5,
for sub array 2,5,9,7,6,10,3,1, the decrease sub sequence which start with curr elem 2 is: 1,2,
for sub array 4,2,5,9,7,6,10,3,1, the decrease sub sequence which start with curr elem 4 is: 1,3,4,
4, 5, 9, 7, 6, 3, 1,
*/
