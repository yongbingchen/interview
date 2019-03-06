#include <iostream>
#include <string>
#include <vector>

using namespace std;

class solution {
	public:
		int get_last_word_len(string &s)
		{
			int len = s.size();
			int ret = 0;

			for (int i = 0; i < len; i++) {
				if (s[i] == ' ')
					ret = 0;
				else
					ret++;
			}

			return ret;
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <string> test_vectors = {
		"this is my test case0",
		"this is my test case012",
		"this is my test case03444444",
		"this is my test ",
		"this is my test case07777777777777777",
	};

	for (auto i : test_vectors)
		cout << "for string " << i << ", last word len is " << s.get_last_word_len(i) << endl;
}
