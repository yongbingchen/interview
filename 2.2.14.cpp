#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class lru_cache {
	public:
		lru_cache(int x) : capacity(x)
		{}

		void set(int key, int val)
		{
			/*if key is not find in cache*/
			if (cache_map.find(key) == cache_map.end()) {
				if (cache.size() == capacity) {
					int k = cache.back().key;
					cache_map.erase(k);
					cache.pop_back();
				}
			}
			else {
				/*if already in cache list, just remove it,
				 *then will add it back below.
				 * */
				list<cache_node>::iterator it = cache_map[key];
				cache.erase(it);
				cache_map.erase(key);
			}

			/*put this key to the head of cache list*/
			cache.push_front(cache_node(key, val));
			/*put the key's list addr to hash map*/
			cache_map[key] = cache.begin();
		}

		int get(int key)
		{
			if (cache_map.find(key) == cache_map.end())
				return -1;

			list<cache_node>::iterator it = cache_map[key];

			int ret = it->val;
			set(key, it->val);

			return ret;
		}

		int display(void)
		{
			for (const auto &a : cache)
				cout << "key: " << a.key << " val: " << a.val << endl;
		}

	private:
		int capacity;
		struct cache_node {
			int key;
			int val;
			cache_node(int x, int y) : key(x), val(y)
			{}
		};
		unordered_map <int, list <cache_node>::iterator> cache_map;
		//WHY choose list as container, because it has push_front(val) interface, while the only other container has push_front() is queue
		//which is obviously not suited for cache case (random access)
		list <cache_node> cache;
};

int main(int argc, char **argv)
{
	lru_cache cache(4);

	cache.set(1, 11);
	cache.set(2, 12);
	cache.set(3, 13);
	cache.set(4, 14);
	cout << "first time full " << endl;
	cache.display();
	cache.set(5, 15);
	cout << "put another " << endl;
	cache.display();
	cache.set(6, 16);
	cout << "put another " << endl;
	cache.display();

	cout << "get key 1, val = " << cache.get(1) << endl;
	cache.display();
	cout << "get key 3, val = " << cache.get(3) << endl;
	cache.display();
}
