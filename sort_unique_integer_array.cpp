#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class solution {
public:
	void sort(vector <int> &a)
	{
		int size = a.size();
		for (int i = 0; i < size; i++) {
			int max = INT_MIN;
			int j, max_idx = i;
			for (j = i; j < size; j++) {
				if (a[j] > max) {
					max = a[j];
					max_idx = j;
				}
			}
			move_to_front(a, max_idx);
		}
		/* possible optimization: if larger part of the array is in order, and all the not-inorder elems
		 * are less than the smallest of the part than in order, then can just move those not-inorder elems only
		 */
	}
private:
	void move_to_front(vector <int> &a, int idx)
	{
		for (int i = idx; i > 0; i--)
			swap(a[i], a[i - 1]);
	}
};

int main(int argc, char **argv)
{
	vector <int> a = {9, 8, 7, 6, 5, 4, 3, 2};

	solution s;
	s.sort(a);
	for (auto &i : a)
		cout << i << ", ";
	cout << endl;
}
