#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class solution {
	public:
		int get_longest_consecutive_len(vector <int> &a)
		{
			unordered_map <int, bool> in_sequence;

			for (auto &i : a)
				in_sequence[i] = false;

			int longest = 0;
			for (auto &i : a) {
				if (in_sequence[i])
					continue;

				int len = 1;

				in_sequence[i] = true;

				//search consecutive number fom larger side
				//KEY is do not try to search the array itself, that's O(n2)
				//search a map is O(1), so the whole thing is O(n)
				int j = i + 1;
				while(in_sequence.find(j) != in_sequence.end() && in_sequence[j] == false) {
					in_sequence[j] = true;
					len++;
					j++;
				}

				//search consecutive number fom smaller side
				j = i - 1;
				while(in_sequence.find(j) != in_sequence.end() && in_sequence[j] == false) {
					in_sequence[j] = true;
					len++;
					j--;
				}

				longest = max(longest, len);
			}

			return longest;
		}

		int get_lcs(vector <int> &a)
		{
			vector <int> lcs(a.size(), 0);

			lcs[0] = 1;
			for (int i = 1; i < a.size(); i++) {
				for (int j = 0; j < i; j++) {
					if (a[i] > a[j] && lcs[i] < lcs[j])
						lcs[i] = lcs[j];
				}
				lcs[i] += 1;
			}

			int max_lcs = 0;
			for (auto &i : lcs)
				max_lcs = max(max_lcs, i);
			return max_lcs;
		}

		vector <int> get_longest_increasing_subseq(vector <int> &a)
		{
			vector <vector <int>> lis(a.size());

			lis[0].push_back(a[0]);

			for (int i = 1; i < a.size(); i++) {
				//compare with all sub arrays shorter than curr sub array
				for (int j = 0; j < i; j++) {
					if (a[j] < a[i] && lis[j].size() > lis[i].size()) {
						lis[i] = lis[j];
					}
				}
				lis[i].push_back(a[i]);
			}

			int max_idx = 0;
			for (int i = 0; i < a.size(); i++) {
				if (lis[i].size() > lis[max_idx].size()) {
					max_idx = i;
				}
			}

			return lis[max_idx];
		}


};

int main(int argc, char **argv)
{
	vector <int> test = {100, 4, 2, 3, 18, 11, 15, 12, 14, 13, 17, 16, 1, 5, 7, 6, 9, 8};

	solution s;
	cout << "longest consecutive len is " << s.get_longest_consecutive_len(test) << endl;
	//above result is longer because there's no "sequnce" restriction, the final subset do not need to keep original seqeunce.
	cout << "longest sub seqeunce len " << s.get_lcs(test) << endl;

	vector <int> result = s.get_longest_increasing_subseq(test);
	for (auto &i : result)
		cout << i << ", ";
	cout << endl;

	exit(EXIT_SUCCESS);
}
