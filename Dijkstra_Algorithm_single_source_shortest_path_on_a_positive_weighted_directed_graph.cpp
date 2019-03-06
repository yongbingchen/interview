#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct edge {
	int src;
	int dst;
	int weight;
	edge(int x, int y, int z) : src(x), dst(y), weight(z)
	{}
};

struct node {
	int src;
	int dist;
	node(int x, int y) : src(x), dist(y)
	{}
};

/*
9.9 — Overloading the parenthesis operator
https://www.learncpp.com/cpp-tutorial/99-overloading-the-parenthesis-operator/
All of the overloaded operators you have seen so far let you define the type of the operator’s parameters, but not the number of parameters (which is fixed based on the type of the operator). For example, operator== always takes two parameters, whereas operator! always takes one. The parenthesis operator (operator()) is a particularly interesting operator in that it allows you to vary both the type AND number of parameters it takes.

There are two things to keep in mind: first, the parenthesis operator must be implemented as a member function. Second, in non-object-oriented C++, the () operator is used to call functions. In the case of classes, operator() is just a normal operator that calls a function (named operator()) like any other overloaded operator.

template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class priority_queue;

A priority queue is a container adaptor that provides constant time lookup of the largest (by default) element, at the expense of logarithmic insertion and extraction.

A user-provided Compare can be supplied to change the ordering, e.g. using std::greater<T> would cause the smallest element to appear as the top().

Compare	-	A Compare type providing a strict weak ordering.
Note that the Compare parameter is defined such that it returns true if its first argument comes before its second argument in a weak ordering.
That is, the front of the queue contains the "last" element according to the weak ordering imposed by Compare.
(My own note: if a > b is true in compare(), then in the priority_queue (the vector of objs), the order is ...b...a...)

strict weak ordering
The "strict" just means it is the irreflexive form "<" of the comparison rather than the reflexive "≤". The "weak" means that the absence of both a<b and b<a do not imply that a=b.
The strict weak ordering then induces a (strict) total ordering on the equivalence classes for this equivalence relation.

template <class RandomAccessIterator, class Compare>
  void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
comp //for sort()
Binary function that accepts two elements in the range as arguments, and returns a value convertible to bool. The value returned indicates
whether the element passed as first argument is considered to go before the second in the specific strict weak ordering it defines.
(My own note: in sort(), if a < b is true in compare(), then in the sorted vector, the order is ...a...b...)
*/
class my_greater {
	public:
		bool operator () (node x, node y)
		{
			return x.dist > y.dist;
		}
};

class graph {
	public:
		graph(vector <edge> &edges, int vertices)
		{
			adjacent.resize(vertices);
			for (auto &e : edges) {
				adjacent[e.src].push_back(e);
			}
		}

		int shortest_path(int start, vector <int> &dist, vector <int> &pred)
		{
			priority_queue <node, vector <node>, my_greater> pq;
			//priority_queue will sort elem, always let the "biggest" elem at top/front of the container (vector in this case).
			//when user provided a customized "compare" method, the "smallest" elem will be at top (the case we needed here).
			//CAUTION! do not use "less" or "greater" as third template param, because they are std defined functions.
			pq.push(node(start, 0));
			dist[start] = 0;

			vector <bool> done(adjacent.size(), false);
			while(!pq.empty()) {
				node curr = pq.top(); //top is the current shortest distance elem to the start elem (and not been visited as a source node).
				pq.pop();

				int src = curr.src;
				for (auto &v : adjacent[src]) {
					int dst = v.dst;
					int weight = v.weight;
					cout << "curr source vertex is " << src << ", its curr distanece is " << dist[src] << ", curr dst is " << dst << ", its curr distance is " << dist[dst] << " edge weight is " << weight << ", is dst already processed " << done[dst] << endl;
					if (!done[dst] && dist[src] + weight < dist[dst]) { //only consider this path if it can shorten the distance. (dist[] is obliged to change if it's not visited as a source node)
						dist[dst] = dist[src] + weight;
						pred[dst] = src;
						pq.push(node(dst, dist[dst]));
					}
				}

				//this is the key point of Dijkstra algrithm, the current shortest path top/end node will remain in the final shortest path,
				//because every edge has positive weight, if current top already has minimum path distance, no possible to find shorter path by add another positive edge.
				//so this algrithm only apply to graph with positive edge.
				//for edge with negative weight, use Bellman-Ford algrithm.
				done[src] = true;
			}
		}

	private:
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

	for (int i = 0; i < 1/*vertices*/; i++) {
		vector <int> dist(vertices, INT_MAX);
		vector <int> pred(vertices, -1);
		g.shortest_path(i, dist, pred);
		for (int j = 0; j < vertices; j++) {
			cout << "from " << i << " vertex " << j << ", shortest distance is " << dist[j] << endl;
			cout << "it shortest path is: ";
			int k = j;
			while(pred[k] != -1) {
				cout << k << ", ";
				k = pred[k];
			}
			cout << endl;
		}
	}

	exit(EXIT_SUCCESS);
}
