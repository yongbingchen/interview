#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		vector <int> increasing_subseq_with_max_sum(vector <int> &a)
		{
			vector <vector <int>> incrs(a.size());
			vector <int> sums(a.size());

			//for each elem of the array, find the increasing sub sequnce (by condition a[i] > a[j]) end with curr elem a[i],
			//and has larger sum (by condition sums[i] = sum[j] + a[i]).
			incrs[0].push_back(a[0]);
			sums[0] = a[0];

			//This called bottom up DP method, which start from simplest sub problem,
			//evolve to larger scale problem solution.
			for (int i = 1; i < a.size(); i++) {
				for (int j = 0; j < i; j++) {
					if (a[i] > a[j] && sums[i] < sums[j]) {
						incrs[i] = incrs[j];
						sums[i] = sums[j];
					}
				}
				incrs[i].push_back(a[i]);
				sums[i] += a[i];
			}

			int idx = 0;
			for (int i = 0; i < sums.size(); i++) {
				if (sums[idx] < sums[i])
					idx = i;
			}

			return incrs[idx];
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <int> a = {8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};

	vector <int> result;
	result  = s.increasing_subseq_with_max_sum(a);

	for (auto &i : result)
		cout << i << ", ";
	cout << endl;
}
