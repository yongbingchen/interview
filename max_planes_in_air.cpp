#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution {
	public:
		int max_planes_in_air(vector <pair <int, int>> &flight_time)
		{
			vector <int> took_off;
			vector <int> landed;
			for (int i = 0; i < flight_time.size(); i++) {
				took_off.push_back(flight_time[i].first);
				landed.push_back(flight_time[i].second);
			}

			sort(took_off.begin(), took_off.end()); //implictly use sorted took off time array's idx as cnt of total took off planes
			sort(landed.begin(), landed.end()); //landed time may not in order, needed for lower_bound

			int cnt = 0;
			int max_cnt = 0;
			for (int i = 0; i < flight_time.size(); i++) {
				int cnt = get_planes(took_off[i], i + 1, landed);
				max_cnt = max(cnt, max_cnt);
			}

			return max_cnt;
		}

	private:
		int get_planes(int take_off_time, int took_off_planes, vector <int> &landed)
		{
			auto it = lower_bound(landed.begin(), landed.end(), take_off_time);
			int landed_planes = distance(landed.begin(), it);
			cout << "at take off time " << take_off_time << ", " << took_off_planes << " planes took off, " << landed_planes << " planes already landed" << endl;
			return took_off_planes - landed_planes;
		}
};

int main(int argc, char **argv)
{
	vector <pair <int, int>> flight_time = {
		pair <int, int> (1, 4),
		pair <int, int> (6, 8),
		pair <int, int> (2, 4),
		pair <int, int> (7, 9),
		pair <int, int> (10, 15),
		pair <int, int> (3, 6),
		pair <int, int> (7, 10),
		pair <int, int> (8, 11),
	};

	solution s;
	int ret = s.max_planes_in_air(flight_time);
	cout << ret << endl;

	exit(EXIT_SUCCESS);
}

/*
   at take off time 1, 1 planes took off, 0 planes already landed
   at take off time 2, 2 planes took off, 0 planes already landed
   at take off time 3, 3 planes took off, 0 planes already landed
   at take off time 6, 4 planes took off, 2 planes already landed
   at take off time 7, 5 planes took off, 3 planes already landed
   at take off time 7, 6 planes took off, 3 planes already landed
   at take off time 8, 7 planes took off, 3 planes already landed
   at take off time 10, 8 planes took off, 5 planes already landed
   4
 */
