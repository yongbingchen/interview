#include <iostream>
#include <string>
#include <vector>

using namespace std;

class solution {
	public:
		bool is_valid(string s)
		{
			int len = s.size();

			bool is_first = true;
			bool has_base = false;
			bool need_expo = false;
			for (int i = 0; i < len; i++) {
				if (s[i] == ' ') {
					if (is_first) {
						is_first = false;
						continue;
					}
					if (s[i + 1] == '\0')
						break;
					if (s[i + 1] != ' ')
						return false;
				}
				else if (isdigit(s[i])) {
					if (is_first == true) {
						is_first = false;
					}
					has_base = true;
					if (need_expo)
						need_expo = false;
				}
				else {
					if (s[i] == 'e' && has_base) {
						need_expo = true;
					}
					else if (s[i] == '.' && has_base) {
						need_expo = true;
					}
					else if (s[i] == '\0')
						break;
					else
						return false;
				}
			}

			if (need_expo)
				return false;

			return true;
		}
};

int main(int argc, char **argv)
{
	solution a;
	vector <string> test_vectors = {
                "0",
                " 0.1 ",
                "abc",
                "1 a",
                "2e10",
                "2e",
                "2."
 	};

	for (const auto i : test_vectors)
		cout << "is " << i << " a valid number " << a.is_valid(i) << endl;
}
