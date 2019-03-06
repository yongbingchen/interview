#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class mycompare {
	public:
		bool operator () (pair <int, int> &a, pair <int, int> &b)
		{
			return a.first < b.first;
		}
};

class solution {
	public:
		int get_total_time(vector <pair <int, int>> &intervals)
		{
			sort(intervals.begin(), intervals.end(), mycompare()); //it's compare(), means an object (a real function), but not a class (a type)

			int ret = intervals[0].second - intervals[0].first;
			for (int i = 1; i < intervals.size(); i++) {
				if (intervals[i].first < intervals[i - 1].second)
					ret += intervals[i].second - intervals[i - 1].second;
				else
					ret += intervals[i].second - intervals[i].first;
			}

			return ret;
		}
};

/*
template <class RandomAccessIterator, class Compare>
  void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);

*/
int main(int argc, char **argv)
{
	vector <pair <int, int>> intervals = {
		pair <int, int> (1, 4),
		pair <int, int> (6, 8),
		pair <int, int> (2, 4),
		pair <int, int> (7, 9),
		pair <int, int> (10, 15),
	};

	solution s;
	int ret = s.get_total_time(intervals);
	cout << ret << endl;

	exit(EXIT_SUCCESS);
}

