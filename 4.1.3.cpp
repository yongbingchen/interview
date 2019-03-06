#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		int largest_rect(vector <int> &a)
		{
			int max_a = 0;
			vector <int> area(a.size(), 0);

			for (int i = 0; i < a.size(); i++) {
				int left = i;
				for (int j = i; j >= 0; j--) {
					if(a[j] < a[i]) {
						break;
					}
					left = j;
				}

				int right = i;
				for (int j = i; j < a.size(); j++) {
					if(a[j] < a[i]) {
						break;
					}
					right = j;
				}

				area[i] = a[i] * (right - left + 1);
				max_a = max(max_a, area[i]);
			}

			return max_a;
		}
};

int main(int argc, char **argv)
{
	solution a;

	vector <vector <int>> test_vectors = {
		{2, 1, 5, 6, 2, 3},
		{1, 2, 3, 4, 5, 6},
		{6, 5, 4, 3, 2, 1},
		{2, 2, 2, 2, 2, 2}
	};

	for (auto v : test_vectors) {
		for (auto i : v)
			cout << i << " ";
		cout << endl;

		cout << "has largest rectangle " << a.largest_rect(v) << endl;
	}
}
