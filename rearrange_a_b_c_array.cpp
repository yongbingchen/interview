#include <iostream>
#include <vector>

using namespace std;

class solution {
public:
	void reorder(vector <char> &a)
	{
		for (int i = 0; i < a.size(); i++) {
			if (i % 3 == 0) {
				swap_with_next(a, i, 'a');
			}
			else if (i % 3 == 1) {
				swap_with_next(a, i, 'b');
			}
			else if (i % 3 == 2) {
				swap_with_next(a, i, 'c');
			}
		}
	}
private:
	void swap_with_next(vector <char> &a, int idx, char target)
	{
		if (a[idx] == target)
			return;

		for (int i = idx + 1; i < a.size(); i++) {
			//find next target which is not in final position
			if (a[i] == target && (i % 3) != (a[i] - 'a')) {
				swap(a[i], a[idx]);
				return;
			}
		}
	}
};


int main(int argc, char **argv)
{
	vector <vector <char>> test_vectors {
		{'a', 'b', 'c'},
		{'a', 'a', 'b', 'b', 'c', 'c'},
		{'a', 'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c'},
		{'a', 'a', 'a', 'a', 'b', 'b', 'b', 'b', 'c', 'c', 'c', 'c'},
		{'a', 'a', 'a', 'a', 'a', 'b', 'b', 'b', 'b', 'b', 'c', 'c', 'c', 'c', 'c'},
	};

	solution s;

	for (auto &v : test_vectors) {
		s.reorder(v);
		for (auto &i :v)
			cout << i << ", ";
		cout << endl;
	}
}
