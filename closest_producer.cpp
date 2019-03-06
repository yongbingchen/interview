#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
struct coordinate {
	int x;
	int y;
	int dist;
	coordinate(int a, int b) : x(a), y(b), dist(0)
	{}
};

class my_compare {
public:
	bool operator() (coordinate &a, coordinate &b)
	{ return a.dist < b.dist; }
};

class solution {
public:
	void closest(vector <int> &consumers, vector <coordinate> &producers, vector <coordinate> &result)
	{
		sort(consumers.begin(), consumers.end());

		for (auto &i : producers)
			i.dist = get_distance_sqr(i, consumers[0]);

		//sort the producers based on their distance to 'x', the
		//'smallest' one is the most left one to 'x' (marked with
		//negative distance)
		sort(producers.begin(), producers.end(), my_compare());
		auto it = producers.begin();
		for (; it != producers.end(); it++) {
			if (abs(it->dist) < abs(next(it)->dist)) {
				result.push_back(*it);
				break;
			}
		}

		for (int i = 1; i < consumers.size(); i++) {
			auto max_it = it;
			int min_dist = INT_MAX;
//only search start from last result, because  (x + x') can not get closer to the producers 'left' to the x;
//through this achieved complexity less than consumers.size() * producers.size()
			for (auto t = it; t != producers.end(); t++) {
				int dist = get_distance_sqr(*t, consumers[i]);
				if (abs(dist) < min_dist) {
					min_dist = abs(dist);
					max_it = t;
				}
			}
			it = max_it;
			result.push_back(*max_it);
		}
	}

private:
	int get_distance_sqr(coordinate &p, int x)
	{
		int dist = (p.x - x) * (p.x - x) + p.y * p.y;
		if (p.x < x)
			return dist * -1;
		else
			return dist;
	}
};


int main(int argc, char **argv)
{
	vector <int> consumers = {1, 5, 7, 10, 20, 30, 40, 50, 60, 100};
	vector <coordinate> producers = {
		coordinate(2, 0),
		coordinate(0, 3),
		coordinate(1, 1),
		coordinate(3, 2),
		coordinate(8, 10),
		coordinate(9, 100),
		coordinate(100, 9),
	};

	solution s;
	vector <coordinate> ret;
	s.closest(consumers, producers, ret);
	for (int i = 0; i < consumers.size(); i++)
		cout << "for consumer " << consumers[i] << ", closest producer is (" << ret[i].x << ", " << ret[i].y << ")" << endl;
}
