#include <iostream>
#include <string>
#include <algorithm> //for reverse()

using namespace std;

class solution {
	public:
		/* c++ now prohibit pass 'string &' as parameter,
		 * see https://stackoverflow.com/questions/10231349/are-the-days-of-passing-const-stdstring-as-a-parameter-over
		 * */
		//string add_binary(string &s1, string &s2)
		string add_binary(string s1, string s2)
		{
			reverse(s1.begin(), s1.end());
			reverse(s2.begin(), s2.end());

			int bits = s1.size() > s2.size() ?
				s1.size() : s2.size();

			int carry = 0;
			string result;
			for (int i = 0; i < bits; i++) {
				int bit = (s1[i] - '0') + (s2[i] - '0') + carry;
				carry = bit / 2;
				bit %= 2;
				result.insert(result.begin(), bit + '0');
			}

			if (carry != 0)
				result.insert(result.begin(), '1');

			return result;
		}

		string add_binary_2(string s1, string s2)
		{
			auto p1 = s1.rbegin();
			auto p2 = s2.rbegin();
			int carry = 0;
			string result;

			while(p1 != s1.rend() && p2 != s2.rend()) {
				char bit = carry + *p1  - '0' + *p2 - '0';
				carry = bit / 2;
				bit %= 2;
				bit += '0';
				result = bit + result;
				p1++;
				p2++;
			}

			while(p1 != s1.rend()) {
				char bit = carry + *p1  - '0';
				carry = bit / 2;
				bit %= 2;
				bit += '0';
				result = bit + result;
				//ERROR!(bit %2) is an intege, which is not allowed to add to a string.`
				//result = (bit % 2) + '0' + result;
				p1++;
			}

			while(p2 != s2.rend()) {
				char bit = carry + *p2  - '0';
				carry = bit / 2;
				bit %= 2;
				bit += '0';
				result = bit + result;
				p2++;
			}

			if (carry)
				result = '1' + result;

			return result;
		}
};

int main(int argc, char **argv)
{
	solution a;

	cout << a.add_binary("11", "1") << endl;
}

