#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class solution {
public:
	void next_permutation(vector <int> &a)
	{
		//find pivot: the first elem from right to left who break the ascending order
		auto pivot = a.rbegin();
		for (auto it = a.rbegin(); it != a.rend(); it++) {
			if (*it > *next(it)) {
				pivot = next(it);
				break;
			}
		} //for {1, 2, 3}, pivot num is 2

		//this means the array is in full order '3, 2, 1'
		if (pivot == a.rbegin()) {
			reverse(a.begin(), a.end());
			return;
		}

		//find the elem from [right(pivot), a.end()], which is the first elem larger than pivot elem.
		auto change = a.rbegin();
		for (auto it = a.rbegin(); it != a.rend(); it++) {
			if (*it > *(pivot)) {
				change = it;
				break;
			}
		} //for {1, 2, 3}, chaneg num is 3

		//swap the pivot and the change:
		swap(pivot, change); //for {1, 2, 3}, now, it's {1, 3, 2}
		//reverse the range [right(pivot), a.end()],
		reverse(a.rbegin(), pivot); //pivot is a reverse iterator, can not call reverse(next(pivot), a.end())
		//for {1, 2, 3}, after swap {1, 3, 2}, then reverse to {1, 3, 2}, because a.rbegin() == right(pivot)
	}
};

int main(int argc, char **argv)
{
	vector <vector <int>> test_vectors = {
		{1, 2, 3}, //remember this, its next permutation is 1, 3, 2, use this to guide to coding.
		{3, 2, 1},
		{1, 3, 2},
		{1, 2},
		{3, 1, 5},
		{5, 8, 3},
		{1, 2, 3, 8, 9},
		{3, 4, 7, 2, 2, 6, 4, 1},
	};

	solution s;

	for (auto &v : test_vectors) {
		s.next_permutation(v);
		for (auto &i : v)
			cout << i << ", ";
		cout << endl;
	}
}
