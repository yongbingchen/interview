#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		int candy(vector <int> &rating)
		{
			int result = 0;
			vector <int> num(rating.size(), 1);
			//scan from left to right
			for (int i = 1; i < rating.size(); i++) {
				if (rating[i] > rating[i - 1]) {
					num[i] = max(num[i - 1] + 1, num[i]);
					cout << "first kid with rating " << rating[i] << " get " << num[i] << " candy" << endl;
					cout << "because his rating is higher than neighbor " << rating[i - 1] << " with candy " << num[i - 1] << endl;
				}
			}
			//then scan from right to left
			for (int i = rating.size() - 2; i > 0; i--) {
				if (rating[i] > rating[i + 1]) {
					//if this kid already has enough candy to satisfy the requiement 2, no need for further candy.
					num[i] = max(num[i + 1] + 1, num[i]);
					cout << "then kid with rating " << rating[i] << " get " << num[i] << " candy" << endl;
					cout << "because his rating is higher than neighbor " << rating[i + 1] << " with candy " << num[i + 1] << endl;
				}
			}
			for (int i = 0; i < rating.size(); i++ ) {
				cout << "kid with rating " << rating[i] << " get " << num[i] << " candy" << endl;
				result += num[i];
			}
			return result;
		}
};

int main(int argc, char **argv)
{
	vector <int> rating = {1, 2, 3, 5, 4, 2};
	solution s;

	int ret = s.candy(rating);
	cout << "candy number is " << ret << endl;

	exit(EXIT_SUCCESS);
}

