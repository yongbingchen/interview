#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct edge {
	int src;
	int dst;
};

class graph {
	public:
		graph(vector <edge> &edges, int vertices)
		{
			adjacent.resize(vertices);
			for (auto &e : edges) {
				adjacent[e.src].push_back(e.dst);
				adjacent[e.dst].push_back(e.src);
			}
		}

		bool check_cycle(int start)
		{
			queue <int> q;
			vector <bool> discovered(adjacent.size(), false);
			vector <int> predecessor(adjacent.size(), -1);

			q.push(start);
			discovered[start] = true;
			while(!q.empty()) {
				int v = q.front();
				q.pop();

				for (auto &i : adjacent[v]) {
					if (!discovered[i]) {
						predecessor[i] = v;
						q.push(i);
						discovered[i] = true; //this flag is for avoiding pushing same node into queue multiple times, so put it here.
					}
					else {
						if (i != predecessor[v]) {
							cout << "node " << i << " is discovered, and it's not its parent " << v << "'s predecessor " << predecessor[v] << endl;
							return true;
						}
					}
				}
			}

			return false;
		}

	private:
		vector <vector <int>> adjacent;
};

int main(int argc, char **argv)
{
	vector <edge> edges = {
		{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
		{5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}, {6, 10}
		// edge (6->10) introduces a cycle in the graph
	};

	int vertices = 13;
	graph g(edges, vertices);

	bool ret = g.check_cycle(1);
	cout << "does graph have cycle ? " << ret << endl;

	exit(EXIT_SUCCESS);
}
