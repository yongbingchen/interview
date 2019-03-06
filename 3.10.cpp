#include <iostream>
#include <string>
#include <vector>

using namespace std;

class solution {
public:
        string int_to_roman(int val)
        {
                string result;

                int total = radix.size();
                for (int i = 0; i < total; i++) {
                        int count = val / radix[i];
                        for (int j = 0; j < count; j++)
                                /*use '+' instead of strcat for c++11*/
                                result += symbol[i];
                        val %= radix[i];
                }

                return result;
        }
private:
        vector <int> radix = {1000, 500, 100, 50, 10, 5, 1};
        vector <string> symbol = {"M", "D", "C", "L", "X", "V", "I"};
};

int main(int argc, char **argv)
{
        solution s;

        vector <int> test_vectors = {1, 5, 7, 9, 15, 35, 135, 765, 1024,
                3999};

        for (auto a : test_vectors)
                cout << "int num " << a << " to roman is " << s.int_to_roman(a)
                        << endl;
}

/*
int num 1 to roman is I
int num 5 to roman is V
int num 7 to roman is VII
int num 9 to roman is VIIII
int num 15 to roman is XV
int num 35 to roman is XXXV
int num 135 to roman is CXXXV
int num 765 to roman is DCCLXV
int num 1024 to roman is MXXIIII
int num 3999 to roman is MMMDCCCCLXXXXVIIII
*/
