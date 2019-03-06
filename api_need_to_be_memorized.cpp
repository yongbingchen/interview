1. hash map

#include <unordered_map>

unordered_map <int, bool> my_map;
my_map[key] = false;
my_map.find(key) != my_map.end();
unordered_map <int, bool>::const_iterator entry =
my_map.find(key);
map.erase(key); //erase a node by key, not by iterator, like other containers.
if (entry != my_map.end()) {
	cout << "found in map with key " << entry->first << " has value " << entry->second;
}
//iterate over a map
for (auto it = map.begin(); it != map.end(); it++) {
	closest = min(closest, it->first);
}
for (auto it = map.begin(); it != map.end(); it++) {
	if (it->first == closest) {
		vector <int> ret = {closest, it->second.first, it->second.second};
		return ret;
	}
}


2. max / min
#include <algorithm>
longest = max(longest, curr);
abs_val = abs(val);

3. pair
no include needed;
pair <int, int> entry(key, val);
int key = entry.first;
int val = entry.second;

4. sort
#include <algorithm>

vector <int> a;
sort(a.begin(), a,end());

5. vecotr
#include <vector>
an element can be push_back() to add.
to create a vector with desired len and default val:
vector <int> factor(a.size(), 0);
do not try to create an element by set value only;
/*
 *! ERROR! segmentation fault.
 vector <int> factor;
 factor[0] = 1;
 for (int i = 1; i < a.size(); i++) {
 factor[i] =  factor[i - 1] * i;
 }
 */
clear all element in a vector:
all_elem.clear();
delete one element in vector:
all_elem.erase(all_elem.begin + 5);
//insert an element to special position (head of the vector)
a.insert(a.begin(), 1);
auto it = a.begin();
a.insert(it, e); //insert to pos ahead of it
//for a vector of vector (matrix), how to create the second layer vector dynamically, before any
//element can be push_back to this new second layer vector.
vector <vector <int>> result;
level_traversal_priv(root, 1, result);
if (result.size() < level)
	result.push_back(vector <int>());
	result[level - 1].push_back(root->val);

//erase will return next it
for (auto it = a.begin(); it != a.end(); ) {
	it = a.erase(it);

6. string
//c++ now prohibit pass 'string &' as parameter,
//string add_binary(string &s1, string &s2)
string add_binary(string s1, string s2)
create string from a vector:
string str(v.begin(), v.end());
transform(s.begin(), s.end(), s.begin(), ::tolower);
//use char pointer to process a string:
bool is_match(const string &s, const string &p)
      return _is_match(s.c_str(), p.c_str());
bool _is_match(const char *s, const char *p)

if (!isdigit(s[i]))
else if (!isalnum(*right)) {
//revsers travel a string as a container
	auto p1 = s1.rbegin();
	auto p2 = s2.rbegin();
	while(p1 != s1.rend() && p2 != s2.rend()) {
		p1++; p2++;
	}

//reverse a string (or any container)
#include <algorithm>
reverse(s1.begin(), s1.end());

/*substr(), copy from param1 char, till param2 char, to a new sub string*/
return s[0].substr(0, idx);

7. list
#include <list>
//access last element
int k = cache.back().key;
//insert from front, only container support this except queue
cache.push_front(cache_node(key, val));
cache.pop_back();
//access last and first element:
auto n = cache.back();
map[key] = cache.begin();
cache.erase(it);
//how to reverse a list: head insert method:
//start from head, do not move this point, remove its next, insert to head, loop this till its next is null.
list_node *reverse_list(list_node *h)
{
	list_node *p = h;
	if (p == nullptr || p->next == nullptr)
		return p;

	list_node *new_head = p;
	while(p->next != nullptr) {
		list_node *to_insert = p->next;
		p->next = to_insert->next;
		to_insert->next = new_head;
		new_head = to_insert;
	}

	return new_head;
}

8.stack
#include <stack>
stack <const tree_node *> stk;
if (root != nullptr) stk.push(root);
while(!stk.empty()) {
const tree_node *p = stk.top();
stk.pop();

9.queue
#include <queue>
queue <const tree_node *> this_level, next_level;
this_level.push(root);
while(!this_level.empty()) {
	const tree_node *p = this_level.front();
	this_level.pop();
	swap(this_level, next_level);
