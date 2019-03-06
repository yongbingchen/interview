#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution {
	public:
		int first_missing_positive(vector <int> &nums)
		{
			//issue require O(n) time, only bucket sort with hash_factor 1 can make it.
			bucket_sort_real(nums, 1);

			cout << "its bucket sort result is: ";
			for (const auto &i : nums)
				cout << i << ", ";
			cout << endl;

			for (int i = 0; i < nums.size(); i++) {
				if (nums[i] > 0 && nums[i] + 1 != nums[i +1])
					return nums[i] + 1;
			}

			return nums[nums.size() - 1] + 1;
		}
	private:
		void bucket_sort_real(vector <int> &nums, int hash_factor)
		{
			//1. find out total bucket number.
			int n = nums.size();
			int max = nums[0], min = nums[0];
			for (int i = 0; i < n; i++) {
				max = max > nums[i] ? max : nums[i];
				min = min < nums[i] ? min : nums[i];
			}

			//this factor decide how many total buckets needed.
			//for sparse array, this can be set as array size, but now set to 2.
			//but for this issue, which specifically requires O(n) time, we need to
			//use full bucket to eliminate sort operation inside each bucket.
			int total_buckets = (max - min) / hash_factor + 1; //REMEMBER this +1
			cout << "total buckets " << total_buckets << endl;

			//2. crate these empty buckets:
			vector <int> bucket[total_buckets];
			//vector <vector <int>> bucket(bucket_size);

			//3. use hash method to put elemet into buckets:
			for (const auto &i : nums) {
				//REMEMBER this (i - min), since i maybe negative.
				int bucket_idx = (i - min) / hash_factor;
				bucket[bucket_idx].push_back(i);
			}

			//4. sort the elements fall in same bucket:
			//not necessary if the hash_factor is 1.
			if (hash_factor > 1) {
				for (int i = 0; i < total_buckets; i++)
					sort(bucket[i].begin(), bucket[i].end());
			}

			//5. iterate all buckets, put them back to result
			//now the sort is done.
			int idx = 0;
			for (int i = 0; i < total_buckets; i++) {
				for (const auto &j : bucket[i])
					nums[idx++] = j;
			}
		}

		void bucket_sort_in_book(vector <int> &nums)
		{
			const int n = nums.size();

			for (int i = 0; i < n; i++) {
				//try all elements in array,
				//or bellow cases happened:
				//1. the element is not a positive value
				//2. the element value is larger than array size (means it can not fill into this sorted array anyway.
				//3. or the bucket sort condition meet:
				//nums[i] == nums[nums[i] - 1] == i + 1;

				while(nums[i] != i + 1) {
					if (nums[i] <= 0)
						break;
					if (nums[i] > n)
						break;
					if (nums[i] == nums[nums[i] - 1])
						break;

					swap(nums[i], nums[nums[i] - 1]);
				}
			}
		}


};

int main(int argc, char **argv)
{
	vector <vector <int>> nums = {
		{1, 2, 0},
		{3, 4, 1, 2},
		{9, 1, 5, 2, 4, 7, 3, -1, -3},
		{3, 4, 1},
		{3, 4, -1, 1}
	};

	solution s;

	for (auto & i : nums) {
		cout << "for original array: ";
		for (const auto &j : i)
			cout << j << ", ";
		cout << endl;
		int ret = s.first_missing_positive(i);
		cout << "its first missing positivs is " << ret << endl;
	}

	exit(EXIT_SUCCESS);
}
