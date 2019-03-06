#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
	int src;
	int dst;
	edge(int x, int y) : src(x), dst(y)
	{}
};

class graph {
	public:
		graph(vector <edge> edges, int vertices)
		{
			adjacent.resize(vertices);
			for (auto &e : edges) {
				adjacent[e.src].push_back(e.dst);
				adjacent[e.dst].push_back(e.src);
			}
		}

		void backtracking(int start, int k, vector <int> &color, int &total)
		{
			if (start == adjacent.size()) {
				cout << "total " << ++total << endl;
				for (auto &i : color)
					cout << i << ", ";
				cout << endl;
				return;
			}

			for (int c = 0; c < k; c++) {
				if (is_valid(start, c, color)) {
					color[start] = c;
					backtracking(start + 1, k, color, total);
					color[start] = -1;
				}
			}
		}

	private:
		vector <vector <int>> adjacent;
		bool is_valid(int vertex, int c, vector <int> &color)
		{
			for (auto &j : adjacent[vertex]) {
				if (color[j] == c)
					return false;
			}
			return true;
		}

};

int main(int argc, char **argv)
{
	vector <edge> edges = {
		edge(0, 1),
		edge(0, 4),
		edge(0, 5),
		edge(4, 5),
		edge(1, 4),
		edge(1, 3),
		edge(2, 3),
		edge(2, 4),
		edge(3, 4), //add one edge to reduce total solution, for debugging purpose
	};

	int vertices = 6;
	graph g(edges, vertices);
	int k = 3;
	int total = 0;
	vector <int>color(vertices, -1);
	g.backtracking(0, k, color, total);

	exit(EXIT_SUCCESS);
}
