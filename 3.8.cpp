#include <iostream>
#include <string>
#include <vector>

using namespace std;

class solution {
public:
        string longest_common_prefix(vector <string> &s)
        {
                int num_of_str = s.size();
                int len = s[0].size();

                cout << "check common prefix from num of " << num_of_str << " strings" << endl;

                for (int idx = 0; idx < len; idx++) {
                        for (int i = 0; i < num_of_str; i++) {
                                if (s[i][idx] != s[0][idx])
/*substr(), copy from param1 char, till param2 char, to a new sub string*/
                                        return s[0].substr(0, idx);
                        }
                }

                return s[0];
        }
};

int main(int argc, char **argv)
{
        solution a;

        vector <string> array = {
                "this is my test case",
                "this is my test case again",
                "this is my test case again and again",
                "this is my test case again and again and again",
        };

        cout << a.longest_common_prefix(array) << endl;
}

