#include <iostream>
#include <vector>
#include <string>
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
				cout << "edge from " << e.src << " to " << e.dst << endl;
			}
		}
		void topological_sort(vector <int> &result)
		{
			vector <bool> visited(adjacent.size(), false);
			result.resize(adjacent.size());
			int departure = 0;
			for (int i = 0; i < adjacent.size(); i++) {
				if (!visited[i]) {
					dfs(i, visited, departure, result);
				}
			}
		}

	private:
		vector <vector <int>> adjacent;
		void dfs(int start, vector <bool> &visited, int &departure, vector <int> &result)
		{
			visited[start] = true;
			for (auto &i : adjacent[start]) {
				if (!visited[i]) {
					cout << "do dfs on " << start << "'s adj " << i << endl;
					dfs(i, visited, departure, result);
				}
			}
			result[departure] = start;
			cout << "vertex " << start << "'s departure " << departure << endl;
			departure++;
		}
};

class solution {
	public:
		void find_char_order(vector <string> &dict, vector <char> &output)
		{
			vector <edge> edges;

			for (int i = 0; i < dict.size() - 1; i++) {
				string word = dict[i];
				string next = dict[i + 1];
				for (int j = 0; j < min(word.size(), next.size()); j++) {
					if (word[j] != next[j]) {
						edges.push_back(edge(word[j] - 'a', next[j] - 'a'));
						break; //!ONLY FIRST DIFF COUNT! you are suppose to get only one char order from one pair of adjacent words.
					}
				}
			}

			graph g(edges, 4);
			vector <int> result;
			g.topological_sort(result);
			for (auto it = result.rbegin(); it != result.rend(); it++)
				output.push_back(*it + 'a');
		}
};

int main(int argc, char **argv)
{
	vector <string> dict = {"baa", "abcd", "abca", "cab", "cad"};
	vector <char> output;

	solution s;
	s.find_char_order(dict, output);
	for (auto &c : output)
		cout << c << ", ";
	cout << endl;

	exit(EXIT_SUCCESS);
}
