#include <iostream>
#include <vector>

using namespace std;

/*KEY POINT:
 * 0. NOT all search range (first, last) has the pivot issue (after iterate for a while), keep this in mind.
 * 1. always try to elimniate the half range with good order (no pivot point), do not try to guess where's the target in the bad sequence (with pivot point).
 * 2. whenever use target to compare, return if equal immediately, otherwise some corner case may never found in your code.
 * 3. only do mid +/- 1 for optimize, risky at interview and not worth it.
 */

class solution {
	public:
		int search(vector <int> &a, int target)
		{
			int first = 0;
			int end = a.size() - 1;

			while(first < end) {
				int mid = first + (end - first) / 2;

				if (a[mid] == target)
					return mid;

				if (target < a[mid]) {
					if (a[mid] < a[end]) {
						end = mid;
					}
					else {//[mid, end] part has a pivot point, so [f, mid] is in order
						//if target is less than the smallest of this half sequence, then skip this half.
						if (target == a[first])
							return first;

						if (target < a[first]) {
							first = mid;
						}
						else {
							end = mid;
						}
					}

				}
				else {
					if (a[mid] < a[end]) {
						if (target == a[end])
							return end;

						if (target > a[end]) { //drop this in order half [m, end]
							end = mid;
						}
						else {
							first = mid;
						}
					}
					else { //[f, mid] is in order, already larger than its biggest one, so drop it.
						first = mid;
					}
				}
			}

			return -1;
		}
};

int main(int argc, char **argv)
{
	vector <int> test = {4, 5, 6, 7, 8, 0, 1, 2, 3};

	solution s;
	for (auto &i : test) {
		int idx = s.search(test, i);
		cout << "search for " << i << " in array, got result " << test[idx] << endl;
	}

	exit(EXIT_SUCCESS);
}
