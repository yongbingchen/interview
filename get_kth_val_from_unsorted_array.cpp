#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class my_greater {
public:
	bool operator () (int &a, int &b)
	{return a > b;}
};

class solution {
public:
	int get_kth(vector <int> &a, int k)
	{
		priority_queue <int, vector <int>, my_greater> pq;

		for (int i = 0; i < k; i++)
			pq.push(a[i]);

		for (int i = k; i < a.size(); i++) {
			if (a[i] > pq.top()) {
				pq.pop();
				pq.push(a[i]);
			}
		}

		return pq.top();
	}
};

int main(int argc, char **argv)
{
	vector <int> a = {7, 9, 11, 0, 6, 8, 9, 2};
	solution s;
	for (int k = 1; k < 5; k++) {
		cout << k << "th val is " << s.get_kth(a, k) << endl;
	}
}
