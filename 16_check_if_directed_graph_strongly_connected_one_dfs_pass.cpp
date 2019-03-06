#include <iostream>
#include <vector>

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
			for (auto &i : edges)
				adjacent[i.src].push_back(i.dst);
		}

		bool is_strongly_connected(void)
		{
			vector <bool> visited(adjacent.size(), false);
			int visit_order = 0, highest_subtree_order = 0;
			vector <int> vo(adjacent.size(), -1);
			return dfs(0, visit_order, highest_subtree_order, vo, visited);
		}

	private:
		bool dfs(int start, int &visit_order, int &highest_subtree_order, vector <int> &vo, vector <bool> &visited)
		{
			if (visited[start])
				return false;

			visited[start] = true;
			visit_order++;
			vo[start] = visit_order;
			highest_subtree_order = visit_order;
			for (auto &i : adjacent[start]) {
				if (!visited[i]) {
					int tmp;
					if (dfs(i, visit_order, tmp, vo, visited))
						return true;
					if (tmp > vo[start])
						return true;
					highest_subtree_order = min(highest_subtree_order, tmp);
				}
				else {
					highest_subtree_order = min(vo[start], vo[i]);
				}
			}

			return false;
		}

		vector <vector <int>> adjacent;
};

int main(int argc, char **argv)
{
	vector <edge> edges = {
		{0, 4}, {1, 0}, {1, 2}, {2, 1}, {2, 4}, {3, 1}, {3, 2}, {4, 3}
		//{0, 4}, {1, 0}, {2, 1}, {2, 4}, {3, 1}, {3, 2}, {4, 3} //not
	};

	int vertices = 5;
	graph g(edges, vertices);

	bool ret = g.is_strongly_connected();
	cout << "is graph strongly connected? " << ret << endl;

	exit(EXIT_SUCCESS);
}
