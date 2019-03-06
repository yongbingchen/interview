#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		int search_insert_pos(const vector <int> array, const int target)
		{
			auto lower = lower_bound(array.begin(), array.end(), target);

			return distance(array.begin(), lower);
		}

		//this param typename template is an imdispensible part of the
		//template function, do not insert any sentence between them.
		template <typename forward_iterator, typename T>
		forward_iterator lower_bound(forward_iterator begin, forward_iterator end, T target)
		{
			while(begin != end) {
				auto mid = next(begin, distance(begin, end) / 2);

				if (target > *mid)
					begin = mid + 1;
				else
					end = mid;
			}

			return begin;
		}
};

int main(int argc, char **argv)
{
	vector <int> test = {1, 3, 5, 6};
	vector <int> target = {2, 1, 4, 0};
	solution s;

	for (const auto &i : target)
		cout << s.search_insert_pos(test, i) << endl;
	//WRONG! can not call a member function without an instance.
	//solution::lower_bound(test.begin(), test.end(), target[0]);
	//
	//CAUTION! how to instantialize a template function.
	auto it = s.lower_bound<vector <int>::iterator, int>(test.begin(), test.end(), target[0]);
	cout << "call lower bound directly " << distance(test.begin(), it) << endl;
}
