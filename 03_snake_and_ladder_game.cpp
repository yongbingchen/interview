#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <memory> //for unique_ptr
#include <climits>

using namespace std;

struct edge {
	int src;
	int dst;
	edge(int x, int y) : src(x), dst(y)
	{}
};

class graph {
	public:
		graph(vector <edge> &edges, int vertices)
		{
			adjacent.resize(vertices);
			for (auto &e : edges)
				adjacent[e.src].push_back(e.dst);
		}

		int shortest_path_bfs(int start, int stop, vector <int> &path)
		{
			vector <bool> discovered(adjacent.size(), false);
			queue <int> q;

			vector <int> distance(adjacent.size(), INT_MAX);
			vector <int> predecessor(adjacent.size(), -1); //this for keeping back track of the shortest path.

			q.push(start);
			distance[start] = 0;
			discovered[start] = true;
			while(!q.empty()) {
				int v = q.front();
				q.pop();

				for (auto &u : adjacent[v]) {
					if (!discovered[u]) {
						discovered[u] = true;
						q.push(u);
						predecessor[u] = v;
						distance[u] = distance[v] + 1;
						//use bfs, first time reach end point must be the shortest path (when distance between each nodes always be 1)
						if (u == stop) {
							int shortest_path = distance[u];
							path.push_back(u);
							while(predecessor[u] != -1) {
								path.push_back(predecessor[u]);
								u = predecessor[u];
							}
							return shortest_path;
						}
					}
				}
			}

			return INT_MAX;
		}

	private:
		vector <vector <int>> adjacent;

};

class solution {
	public:
		void build_graph(unordered_map <int, int> &snake, unordered_map <int, int> &ladder)
		{
			vector <edge> edges;
			int vertices = 101; //+1 because first node is 1
			for (int i = 1; i < vertices; i++) {
				for (int j = 1; j < 7; j++) {
					int jump_to = i + j;
					if (snake.find(jump_to) != snake.end()) {
						edges.push_back(edge(i, snake[jump_to]));
					}
					else if (ladder.find(jump_to) != ladder.end()) {
						edges.push_back(edge(i, ladder[jump_to]));
					}
					else {
						if (jump_to < vertices)
							edges.push_back(edge(i, jump_to));
					}
				}
			}

			g = make_unique <graph> (edges, vertices);
		}

		int find_shortest_path(vector <int> &path)
		{
			return g->shortest_path_bfs(1, 100, path);
		}

	private:
		unique_ptr <graph> g;
};

int main(int argc, char **argv)
{
	unordered_map <int, int> snake;
	snake[17] = 7;
	snake[54] = 34;
	snake[62] = 19;
	snake[64] = 60;
	snake[87] = 36;
	snake[93] = 73;
	snake[95] = 75;
	snake[98] = 79;

	unordered_map <int, int> ladder;
	ladder[1] = 38;
	ladder[4] = 14;
	ladder[9] = 31;
	ladder[21] = 42;
	ladder[28] = 84;
	ladder[51] = 67;
	ladder[72] = 91;
	ladder[80] = 99;

	solution s;
	s.build_graph(snake, ladder);
	vector <int> path;
	int ret = s.find_shortest_path(path);
	cout << "minimum throws to win is " << ret << endl;
	for (auto &i : path)
		cout << i << ", ";
	cout << endl;

	exit(EXIT_SUCCESS);
}
