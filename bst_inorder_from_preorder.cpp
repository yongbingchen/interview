#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution {
public:
	void get_inorder(vector <int> &preorder, vector <int> &inorder)
	{
		get_inorder(preorder.begin(), preorder.end(), inorder);
	}

private:
	template <typename iterator>
	void get_inorder(iterator pre_start, iterator pre_end, vector <int> &inorder)
	{
		if (pre_start == pre_end)
			return;

		int root = *pre_start;
		iterator right_start = upper_bound(pre_start, pre_end, root);
		get_inorder(next(pre_start), right_start, inorder);
		inorder.push_back(root);
		get_inorder(right_start, pre_end, inorder);
	}

};

int main(int argc, char **argv)
{
	vector <int> preorder = {10, 5, 1, 7, 40, 50};
	solution s;
	vector <int> inorder;
	s.get_inorder(preorder, inorder);
	for (auto &i : inorder)
		cout << i << ", ";
	cout << endl;

	exit(EXIT_SUCCESS);
}
