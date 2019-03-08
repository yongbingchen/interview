#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct edge {
	int src;
	int dst;
	int weight;
};

struct node {
	int vertex;
	int dist;
	node(int x, int y) : vertex(x), dist(y)
	{}
};

class graph {
	public:
		graph(vector <edge> &edges, int v)
		{
			vertices = v;
			adjacent.resize(v);
			for (auto &e : edges)
				adjacent[e.src].push_back(e);
		}

		void shortest_path(int start, vector <int> &dist, vector <int> &pred)
		{
			auto my_greater = [] (const node &a, const node &b) { return a.dist > b.dist; };
			priority_queue <node, vector <node>, decltype(my_greater)> pq(my_greater);
			vector <bool> done(vertices, false);

			dist[start] = 0;
			pq.push(node(start, 0));
			while(!pq.empty()) {
				node u = pq.top();
				pq.pop();
				int src = u.vertex;

				for (auto &v : adjacent[src]) {
					if (!done[v.dst] && dist[v.dst] > dist[src] + v.weight) {
						dist[v.dst] = dist[src] + v.weight;
						pred[v.dst] = src;
						pq.push(node(v.dst, dist[v.dst]));
					}
				}
				done[src] = true; //curr shortest path vertex is in the final shortest path.
			}
		}
	private:
		int vertices;
		vector <vector <edge>> adjacent;

};


int main(int argc, char **argv)
{
	vector <edge> edges = {
		{0, 1, 10}, {0, 4, 3}, {1, 2, 2}, {1, 4, 4}, {2, 3, 9},
		{3, 2, 7}, {4, 1, 1}, {4, 2, 8}, {4, 3, 2}
	};
	int vertices = 5;

	graph g(edges, vertices);

	vector <int> dist(vertices, INT_MAX);
	vector <int> pred(vertices, -1);
	g.shortest_path(0, dist, pred);
	for (int i = 0; i < vertices; i++) {
		cout << "from 0 to vertex " << i << ", shortest distance is " << dist[i] << endl;
		cout << "it shortest path is: ";
		int j = i;
		while(pred[j] != -1) {
			cout << j << ", ";
			j = pred[j];
		}
		cout << endl;
	}

	exit(EXIT_SUCCESS);
}
