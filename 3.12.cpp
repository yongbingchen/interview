#include <iostream>
#include <string>
#include <vector>

using namespace std;

class solution {
	public:
		string count(string s)
		{
			string ret;
			int idx = 0;
			while(s[idx] != '\0') {
				int cnt = 1;
				while(s[idx] == s[idx + 1]) {
					cnt++;
					idx++;
				}
				ret += to_string(cnt);
				ret += s[idx];
				idx++;
			}

			return ret;
		}
};

int main(int argc, char **argv)
{
        solution s;
        vector <string> test_vectors = {"0", "1", "11", "21", "77778"};

        for (auto i : test_vectors)
                cout << "for int " << i << ", its count_and_say is " << s.count(i) << endl;
}
