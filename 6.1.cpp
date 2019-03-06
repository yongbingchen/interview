#include <iostream>
#include <vector>

using namespace std;

class solution {
public:
        vector <int> merge_sorted_array(vector <int> &a,
                        const int a_num,
                        vector <int> &b,
                        const int b_num)
        {
                int merged_size = a_num + b_num;

                int j = a_num - 1;
                int k = b_num - 1;
                for (int i = merged_size - 1; i >= 0; i--) {
                        if (a[j] > b[k]) {
                                a[i] = a[j];
                                j--;
                        }
                        else {
                                a[i] = b[k];
                                k--;
                        }

			//FIXME! there's some case in which j may run into -1
                }

                return a;
        }
};

int main(int argc, char **argv)
{
        solution s;

        vector <int> a = {2, 4, 6, 8, 9, 11, 13, 0, 0, 0, 0, 0, 0, 0, 0};
        vector <int> b = {1, 3, 5, 7, 10, 12, 14, 15};


        vector <int> ret = s.merge_sorted_array(a, 7, b, 8);

        for (const auto &i : ret)
                cout << i << ", ";
        cout << endl;

        exit(EXIT_SUCCESS);
}

