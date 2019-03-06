#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class map_with_last {
public:
	void set(string key, int val)
	{
		auto it = map.find(key);
		if (it != map.end()) {
			auto l_it = find(last.begin(), last.end(), it);
			if (l_it != last.end())
				last.erase(l_it);
		}

		map[key] = val;
		it = map.find(key);
		last.push_front(it);
	}

	int get(string key)
	{
		auto it = map.find(key);
		if (it == map.end())
			return 0;

		auto l_it = find(last.begin(), last.end(), it);
		if (l_it != last.end())
			last.erase(l_it);

		last.push_front(it);
		return map[key];
	}

	void delete_(string key)
	{
		auto it = map.find(key);
		if (it == map.end())
			return;

		auto l_it = find(last.begin(), last.end(), it);
		if (l_it != last.end())
			last.erase(l_it);
		map.erase(key);
	}

	string last_key(void)
	{
		if (!last.empty())
			return last.front()->first;
		return "";
	}
private:
	unordered_map <string, int> map;
	list <unordered_map <string, int>::iterator> last;
};

int main(int argc, char **argv)
{
	map_with_last s;
	s.set("first", 1);
	s.set("second", 2);
	cout << s.last_key() << endl;
	s.get("first");
	cout << s.last_key() << endl;
	s.set("third", 3);
	cout << s.last_key() << endl;
	s.get("second");
	cout << s.last_key() << endl;
	s.delete_("first");
	cout << "after delet key first, now last key is " << s.last_key() << endl;
	s.delete_("second");
	cout << "after delet key second, now last key is " << s.last_key() << endl;
	s.delete_("third");
	cout << "after delet key third, now last key is " << s.last_key() << endl;
}
