#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		int get_num_of_unique_bst(const int node_num)
		{
			//init vector f, with node num n + 1, init value 0;
			//+1 because the '0' node case need to be considered.
			vector <int> f(node_num + 1, 0);

			f[0] = 1;
			f[1] = 1;

			//f[n] defined as 'n' nodes's unique tree numere,
			//it has 'n' cases which one element be the root,
			//first devide f[n] as the sum of these 'n' cases.
			//then a 'n' nodes tree with certain root 'k', it conbination is:
			//left 'k - 1' nodes 's total num * right 'n - k' nodes total num,
			//bst property limited each sub trees total num, otherwise all remain
			//nodes can go to one side, turn to a permutation problem.
			//which is f[k - 1] * f [n - k];
			//calculate this from n == 0 to target num, this is the whole algorithm.
			for (int i = 2; i <= node_num; i++)
				for (int k = 1; k <= i; k++)
					f[i] += f[k - 1] * f[i - k];

			return f[node_num];
		}

};

int main(int argc, char**argv)
{
	solution a;

	for (int i = 0; i < 10; i++)
		cout << "num of " << i << " node can generate " << a.get_num_of_unique_bst(i) << " of unique bst" << endl;
}
