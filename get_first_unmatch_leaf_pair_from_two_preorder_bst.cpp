#include <iostream>
#include <vector>
#include <algorithm> //for upper_bound

using namespace std;

class solution {
public:
	void find_first_unmatch_pair(vector <int> &p1, vector <int> &p2, pair <int, int> &result)
	{
		vector <int> leaves_1, leaves_2;

		get_all_leaves(p1.begin(), p1.end(), leaves_1);
		get_all_leaves(p2.begin(), p2.end(), leaves_2);

		for (int i = 0; i < leaves_1.size() && i < leaves_2.size(); i++) {
			if (leaves_1[i] != leaves_2[i]) {
				result = pair <int, int>(leaves_1[i], leaves_2[i]);
				return;
			}
		}
	}
private:
	template <typename iterator>
	void get_all_leaves(iterator p_begin, iterator p_end, vector <int> &leaves)
	{
		if (next(p_begin) == p_end) {
			leaves.push_back(*p_begin);
			return;
		}

		//though bst preorder is not sorted, upper_bound still works for this case, because root val is larger than all left subtree node.
		iterator right_root = std::upper_bound(next(p_begin), p_end, *p_begin);
		get_all_leaves(next(p_begin), right_root, leaves);
		get_all_leaves(right_root, p_end, leaves);
	}
};

int main(int argc, char **argv)
{
	vector <int> preorder_1 = {4, 2, 1, 3, 7, 6, 8};
	vector <int> preorder_2 = {4, 2, 1, 3, 6, 5, 7};

	solution s;
	pair <int, int> result;
	s.find_first_unmatch_pair(preorder_1, preorder_2, result);
	cout << result.first << ", " << result.second << endl;
};
