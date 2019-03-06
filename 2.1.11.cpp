#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		int remove_element(vector <int> &a, int target)
		{
			int idx = 0;
			//!trap here, a.size() is changing!
			for (int i = 0; i < a.size(); i++) {
				if (a[i] != target) {
					a[idx++] = a[i];
				}
			}
			return idx;
		}

		int remove_element_it(vector <int> &a, int t)
		{
			vector <int>::iterator it;
			while((it = find(a.begin(), a.end(), t)) != a.end())
				a.erase(it);

			return a.size();
		}

};

int main(int argc, char **argv)
{
	vector <int> t = {1, 2, 3, 5, 8, 2, 7, 2, 9};
	solution s;

	int ret = s.remove_element(t, 2);

	cout << "new len " << ret << endl;
	for (int i = 0; i < ret; i++)
		cout << t[i] << ", ";
	cout << endl;
	exit(EXIT_SUCCESS);
}
