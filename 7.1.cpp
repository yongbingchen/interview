#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		pair <int, int> search_range(const vector <int> &array, int target)
		{
			auto lower = lower_bound(array.begin(), array.end(), target);
			auto upper = upper_bound(lower, array.end(), target);

			if (lower == array.end())
				return pair <int, int> {-1, -1};

			if (*lower != target)
				return pair <int, int> {-1, -1};

			int first = distance(array.begin(), lower);
			//!CAUTION, upper is the first element NOT equals to target.
			//int last = distance(array.begin(), upper);
			int last = distance(array.begin(), prev(upper));

			return pair <int, int> {first, last};
		}
	private:
//		template <typename forward_iterator>
//		template <typename T>

		template <typename forward_iterator, typename T>
		forward_iterator lower_bound(forward_iterator begin, forward_iterator end, T target)
		{
			while(begin != end) {
				auto mid = begin + distance(begin, end) / 2;

				if (target > *mid)
					begin = mid + 1;
				else
					end = mid;
				/* CAUTION! not search for result only, but must be the first position
				else if (target < *mid)
					end = mid;
				else
					return mid;
				*/
			}

			//why return begin?
			//because lower_bound is searching for the FIRST (thus the begin) elem which is
			//NOT LESS than the target, not search for target itself.
			return begin;
		}

		//!CAUTION, template typename need to be right before template funcion
		//it's not like a typedef, which claimed once, and be useful everywhere.
		template <typename forward_iterator, typename T>
		forward_iterator upper_bound(forward_iterator begin, forward_iterator end, T target)
		{
			while(begin != end) {
				auto mid = begin + distance(begin, end) / 2;

				//the '=' is the only difference between lower and upper
				if (target >= *mid)
					begin = mid + 1;
				else
					end = mid;
			}

			return begin;
		}
};

int main(int argc, char **argv)
{
	const vector <int> array = {5, 7, 7, 8, 8, 10};

	solution s;

	pair <int, int> ret = s.search_range(array, 8);

	cout << ret.first << ", " << ret.second << endl;

	exit(EXIT_SUCCESS);
}
