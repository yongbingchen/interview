#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct meeting {
	int start;
	int end;
	int weight;
	int total;
	meeting(int x, int y, int z) : start(x), end(y), weight(z), total(0)
	{}
};

class my_compare {
	public:
		bool operator () (meeting &a, meeting &b)
		{ return a.start < b.start;}
};

class solution {
	public:
		int arrange(vector <meeting> &m, vector <meeting> &result)
		{
			sort(m.begin(), m.end(), my_compare());
			int ret = arrange(m.begin(), m.end(), 0);
			int curr = ret;
			for (int i = 0; i < m.size(); i++) {
				if (curr == m[i].total) {
					result.push_back(m[i]);
					curr -= m[i].weight;
				}
			}

			return ret;
		}

	private:
		template <typename iterator>
		int arrange(iterator start, iterator end, int prev_ending)
		{
			if (start == end)
				return 0;

			int with_curr = 0;
			if (start->start >= prev_ending) {
				with_curr = start->weight + arrange(next(start), end, start->end);
			}

			int wo_curr = arrange(next(start), end, prev_ending);
			int ret = max(with_curr, wo_curr);
			if (with_curr > wo_curr) {
				start->total = ret; //note down the solution for subproblem which include curr elem
				//can not use backtrack to get path of result, because the subproblem's solution (max weight from elem 5 to end which include elem 5) may not in the final solution.
				//as shown in below debug message.
				//cout << start->start << ", " << start->end << ", total " << start->total << endl;
			}
			return ret;
		}

};

int main(int argc, char **argv)
{
	vector <meeting> m = {
		meeting(1, 4, 10),
		meeting(6, 8, 2),
		meeting(2, 4, 5),
		meeting(7, 9, 1),
		meeting(10, 15, 3),
		meeting(3, 6, 5),
		meeting(7, 10, 4),
		meeting(8, 11, 6),
		meeting(7, 11, 5),
	};

	solution s;
	vector <meeting> result;
	int ret = s.arrange(m, result);
	cout << "maximum total weight " << ret << endl;
	for (auto &i : result)
		cout << i.start << ", " << i.end << ", " << i.weight << endl;
}
