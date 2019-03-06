#include <iostream>
#include <vector>

using namespace std;

struct interval {
	int lower;
	int upper;
	interval(): lower(0), upper(0)
	{}
	interval(int x, int y) : lower(x), upper(y)
	{}
};

class solution {
	public:
	vector <interval> insert(vector <interval> &ranges, interval t)
	{
		vector <interval>::iterator it = ranges.begin();

		//there're only three cases: insert, merge, skip to next!
		while(it != ranges.end()) {
			//case 1: found insert position. (ranges are sorted, so this condition is enough)
			if (t.upper < it->lower) {
				cout << "target upper " << t.upper << " less than curr's lower " << it->lower << ", insert target before curr and return" << endl;
				ranges.insert(it, t);
				return ranges;
			}
			//case 2: this is not the insert node, neither does it need merge (target is out of curr's range)
			else if ( t.lower > it->upper) {
				it++;
				continue;
			}
			//case 3: curr node's range overlap with target, need merge its range into target, and delete it from original set.
			else {
				cout << "find curr node range overlap with target:" << endl;
				cout << "curr lower " << it->lower << ", target lower " << t.lower <<endl;
				cout << "curr upper " << it->upper << ", target upper " << t.upper <<endl;
				cout << "after merge, target lower " << t.lower << ", target upper " << t.upper <<endl;
				t.lower = min(t.lower, it->lower);
				t.upper = max(t.upper, it->upper);
				it = ranges.erase(it);
			}
		}

		//not with in ranges, insert at the upper of ranges.
		ranges.push_back(t);

		return ranges;
	}
};

int main(int argc, char **argv)
{
	vector <vector <interval>> test = {
		{interval(1, 3), interval(6, 9)},
		{interval(1, 2), interval(3, 5), interval(6, 7), interval(8, 10), interval(12, 16)}
	};

	vector <interval> targets = {interval(2, 5), interval(4, 9)};

	solution s;

	for (int i = 0; i < test.size(); i++)	{
		vector <interval> ret = s.insert(test[i], targets[i]);
		cout << "get result:" << endl;
		for (auto &k : ret)
			cout << "[" << k.lower << ", " << k.upper << "]";
		cout << endl;
	}

	exit(EXIT_SUCCESS);
}
/*
find curr node range overlap with target:
curr lower 1, target lower 2
curr upper 3, target upper 5
after merge, target lower 2, target upper 5
target upper 5 less than curr's lower 6, insert target before curr and return
get result:
[1, 5][6, 9]
find curr node range overlap with target:
curr lower 3, target lower 4
curr upper 5, target upper 9
after merge, target lower 4, target upper 9
find curr node range overlap with target:
curr lower 6, target lower 3
curr upper 7, target upper 9
after merge, target lower 3, target upper 9
find curr node range overlap with target:
curr lower 8, target lower 3
curr upper 10, target upper 9
after merge, target lower 3, target upper 9
target upper 10 less than curr's lower 12, insert target before curr and return
get result:
[1, 2][3, 10][12, 16]
*/
