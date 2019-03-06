#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution {
	public:
		int longest_consecutive_seq(vector <int> &a)
		{
			bucket_sort(a);

			int longest = 1;
			int curr = 1;
			for (int i = 0; i < a.size() - 1; i++) {
				if (a[i]  + 1 == a[i + 1])
					curr++;
				else
					curr = 1;
				longest = max(longest, curr);
			}
			return longest;
		}
	private:
		//bucket sort is not always at O(n) complexity
		void bucket_sort(vector <int> &a)
		{
			int upper = a[0];
			for (int i = 0; i < a.size(); i++) {
				upper = max(upper, a[0]);
			}
			int bucket_size = upper + 1;

			//CAUTION, correct way to creat a vector with desired length
			//vector <int> bucket(bucket_size, 0);
			//but bucket sort need a matrix.
			vector <int> bucket[bucket_size];
			for (int i = 0; i < a.size(); i++)
				bucket[a[i]].push_back(a[i]);

			int index = 0;
			for (int i = 0; i < bucket_size; i++) {
				if (bucket[i].size() != 0)
					a[index++] = bucket[i][0];
			}
		}
};

int main(int argc, char **argv)
{
	vector <int> test = {100, 4, 1, 3, 2, 9, 8, 7, 11, 10};
	solution s;
	cout << "longest consecutive sequence in test string is " << s.longest_consecutive_seq(test) << endl;
	exit(EXIT_SUCCESS);
}
