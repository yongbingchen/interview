#include <iostream>
#include <vector>

using namespace std;

class solution {
public:
	void move_non_zero(vector <int> &a)
	{
		int start = 0;
		int last = a.size() - 1;

		while(start < last) {
			if (a[start] != 0) {
				if (a[last] == 0) {
					swap(a[start], a[last]);
					last--;
				}
				else
					last--;
			}
			else
				start++;
		}
	}
};

int main(int argc, char **argv)
{
	vector <int> a = {1, 2, 3, 0, 4, 5, 0, 6, 7, 8, 0, 9};

	solution s;
	s.move_non_zero(a);
	for (auto &i : a)
		cout << i << ", ";
	cout << endl;
}
