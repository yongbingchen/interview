#include <iostream>
#include <vector>

using namespace std;

struct node {
	int val;
	node *next;
	node(int x) : val(x), next(nullptr)
	{}
};

class solution {
public:
	node *insert_sort_list(node *l)
	{
		node dummy_head(-1);
		node *result = &dummy_head;
		node *p;

		result->next = l;
		l = l->next;
		while(l != nullptr) {
			//get the node to which the next unsorted
			//node to be inserted as its next.
			node *pos = find_pos_to_insert(l, result);

			//this node's next will be changed after
			//insertion, so keep it in a tmp;
			p = l->next;
			insert_to_result(l, pos);
			l = p;
		}
		return dummy_head.next;
	}

	node *build_list(const vector <int> &v)
	{
		node dummy_head(-1);
		node *p = &dummy_head;

		for (const auto &i : v) {
			p->next = new node(i);
			p = p->next;
		}

		return dummy_head.next;
	}

private:
	node *find_pos_to_insert(node *n, node *result)
	{
		while(result->next != nullptr) {
			if (result->next->val > n->val)
				return result;
			result = result->next;
		}

		//reach to the end of sorted list, insert to the tail of it.
		return result;
	}

	void insert_to_result(node *to_insert, node *pos)
	{
		node *next = pos->next;
		pos->next = to_insert;
		to_insert->next = next;
	}
};

int main(int argc, char **argv)
{
	solution s;
	const vector <int> v = {3, 9, 0, 11, 2, 5, 1, 7};

	node *l = s.build_list(v);

	node *ret = s.insert_sort_list(l);

	while(ret != nullptr) {
		cout << ret->val << ", ";
		ret = ret->next;
	}
	cout << endl;

	exit(EXIT_SUCCESS);
}

