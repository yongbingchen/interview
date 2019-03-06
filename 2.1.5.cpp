#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		int get_median(vector <int> &a, vector <int> &b)
		{
			int mid = (a.size() + b.size()) / 2;
			return get_kth(a.begin(), a.size(), b.begin(), b.size(), mid);
		}

	private:
		int get_kth(vector <int>::iterator a, int len_a, vector <int>::iterator b, int len_b, int k)
		{
			if (len_a > len_b)
				return get_kth(b, len_b, a, len_a, k);
			if (k == 1)
				return min(*a, *b);
			if (len_a == 0)
				return *(b + k - 1);

			int mid_a = min(len_a, k / 2);
			int mid_b = k - mid_a;

			if (*(a + mid_a - 1) < *(b + mid_b - 1)) { //drop the a[0] to a[mid_a - 1] part
				return get_kth(a + mid_a, len_a - mid_a, b, len_b, k - mid_a);
			}
			else if (*(a + mid_a - 1) > *(b + mid_b - 1))
				return get_kth(a, len_a, b + mid_b, len_b - mid_b, k - mid_b);
			else {
				return *(a + mid_a - 1);
			}
		}

};

int main(int argc, char **argv)
{
	vector <int> t1 = {1, 2, 3, 4, 15, 16, 17, 18, 19};
	vector <int> t2 = {7, 8, 9, 10, 11, 17, 18, 19};

	solution s;
	cout << "median is " << s.get_median(t1, t2) << endl;

}
