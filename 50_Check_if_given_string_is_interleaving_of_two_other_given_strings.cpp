#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class solution {
public:
	bool is_interleave(string x, string y, string z, unordered_map <string, bool> &visited)
	{
		string key = x + '|' + y + '|' + z;
		if (visited.find(key) != visited.end())
			return visited[key];

		bool ret;
		if (z == x + y || z == y + x) {
			visited[key] = true;
			return true;
		}

		if (z[0] == x[0]) {
			ret = is_interleave(x.substr(1), y, z.substr(1), visited);
			visited[key] = ret;
			return ret;
		}

		if (z[0] == y[0]) {
			ret = is_interleave(x, y.substr(1), z.substr(1), visited);
			visited[key] = ret;
			return ret;
		}

		visited[key] = false;
		return false;
	}
};

int main(int argc, char **argv)
{
	string x = "ABC";
	string y = "DEF";
	string z = "ADEBCF";

	solution s;
	unordered_map <string, bool> visited;
	bool ret = s.is_interleave(x, y, z, visited);
	cout << "Is " << z << " a interleave string of " << x << " and " << y << "? " << ret << endl;

	exit(EXIT_SUCCESS);
}
