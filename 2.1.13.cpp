#include <iostream>
#include <vector>

using namespace std;

/*permutation 3 5 7 4 1 2 9 6 8's sequence is 98884
 * which is calculated by:
 * 98884 = 2*8! + 3*7! + 4*6! + 2*5! + 0*4! + 0*3! + 2*2! + 0*1! + 0*0!
 * explain: first number 3, there're two numbers LESS than 3,
 * there're 8! number of permutation lead by a number at first digit,
 * so this count for 2*8! number of permutation's sequence is less than the target.
 * for second number 5, there's 4 number LESS than 5, and number 3 is already
 * appeared, so only 3 numbers should be counted, total permutation is 3*7!.*/


/*given contor sequnce number 98884 + 1, how to find the permutaion itself?
 * (98884 + 1 )/ (8!) = 2, means first number in target permutation must be 3.
 * keep on, (98884 + 1) % (8!) = 3*7! + 4*6! + 2*5! + 0*4! + 0*3! + 2*2! + 0*1! + 0*0!
 * then (98884 + 1) % (8!)) / (7!) = 3, number 4 has 3 numbers LESS than it,
 * but 3 already appeared, so the result is 5 (3 numbers LESS than 5 except 3)
 */

class solution {
	public:
		vector <int> get_kth_permutation(int n, int k)
		{
			vector <int> s;
			for (int i = 1; i < n + 1; i++)
				s.push_back(i);

			vector <int> result;
			for (int i = 0; i < n; i++) {
				int base = factorial(n - i - 1);
				int idx = k / base;
				k %= base;
				int t = s[idx];
				result.push_back(t);
				s.erase(s.begin() + idx);
			}
			return result;
		}
	private:
		int factorial(int n)
		{
			int ret = 1;
			for (int i = 1; i < n + 1; i++)
				ret *= i;
			return ret;
		}
};

int main(int argc, char **argv)
{
	solution s;
	for (int k = 0; k < 100; k++) {
		cout << k << "th permutation is: ";
		vector <int> result = s.get_kth_permutation(9, k);
		for (auto &i : result)
			cout << i << ", ";
		cout << endl;
		result.clear();
	}
	exit(EXIT_SUCCESS);
}
