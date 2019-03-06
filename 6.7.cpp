#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution {
	public:
		void sort_color_counting_sort(vector <int> &array)
		{
			int count[3] = {0};

			for (int i = 0; i < array.size(); i++)
				count[array[i]]++;

			int idx = 0;
			for (int color = 0; color < 3; color++) {
				for (int i = 0; i < count[color]; i++)
					array[idx++] = color;
			}
			/*
			for (int i = 0; i < count[0]; i++)
				array[idx++] = 0;

			for (int i = 0; i < count[1]; i++)
				array[idx++] = 1;

			for (int i = 0; i < count[2]; i++)
				array[idx++] = 2;
			*/
		}

		void sort_color_one_pass(vector <int> &array)
		{
			int len = array.size();

			/*
			 * these index represent next insert place, not the position
			 * of last 'color' element.
			 * last color (color '2')'s insert place start from end of the array.
			 * */
			int color_0 = 0;
			//since we do not need move color '1' elements, so no need to maintain
			//this insert place.
			/*int color_1 = 0;*/
			int color_2 = array.size() - 1;

			/*
			 * middle color element '1' should keep in place.
			 * swap color '0' to the start part of the array,
			 * swap color '2' to the end part of the array.
			 * loop till current element cross the color '2' insert place.
			 * that means all elements are in place.
			 * !CAUTION, must cross the color_2, since it's not the start of color_2 elements,
			 * but actually the next insert place, still need to be checked.
			 * */
			for (int i = 0; i < color_2 + 1; ) {
				if (array[i] == 0) {
					//KEY point here, do i++, because color_0 is behind i, so
					//both a[i] and a[color_0] have been checked.
					//while in a[color_2] is not.
					swap(array[i++], array[color_0++]);
				}
				else if (array[i] == 1) {
					i++;
				}
				else { /* array[i] == 2*/
					swap(array[i], array[color_2--]);
				}
			}
		}
};

int main(int argc, char **argv)
{
	vector <vector <int>> arrays ={
		{1, 2, 1, 0, 1, 2, 0, 1, 1, 2, 0},
		{0, 0, 1, 1, 0, 0, 2, 2, 1, 0, 1}
	};

	solution s;

	for (auto &a : arrays) {
		cout << "input array:" << endl;
		for (auto &i : a)
			cout << i << ", ";
		cout << endl;

		s.sort_color_one_pass(a);
		//s.sort_color_counting_sort(a);

		cout << "output array:" << endl;
		for (auto &i : a)
			cout << i << ", ";
		cout << endl;
	}

	exit(EXIT_SUCCESS);
}
