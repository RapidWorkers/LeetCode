#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs_norm(vector<vector<pair<char, bool>>>& area, int x, int y, int N)
{
	queue<pair<int, int>> visit;
	queue<pair<int, int>> next_visit;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> food_pos;

	if (x > 0) {
		visit.push(pair<int, int>(y, x - 1));
	}
	if (x < N - 1) {
		visit.push(pair<int, int>(y, x + 1));
	}
	if (y > 0) {
		visit.push(pair<int, int>(y - 1, x));
	}
	if (y < N - 1) {
		visit.push(pair<int, int>(y + 1, x));
	}

	int eat_time = 0;
	int sz_level = 2;
	int sz_cnt = 0;

	int dist = 1;

	while (!visit.empty() || !next_visit.empty())
	{
		int x_target;
		int y_target;

		if (visit.empty())
		{
			if (!food_pos.empty()) {//food available
				x_target = food_pos.top().first;
				y_target = food_pos.top().second;
				food_pos.pop();

				area[x][y].first = 0;//move shark
				area[x_target][y_target].first = 9;//move shark
				x = x_target; y = y_target;//move shark

				sz_cnt++;
				eat_time += dist;
				dist = 0;

				if (sz_cnt == sz_level)
				{
					sz_cnt = 0;
					sz_level++;
				}

				//if (next_visit.empty()) break;//end here

				while (!next_visit.empty()) {
					next_visit.pop();
				}

				while (!food_pos.empty()) {
					food_pos.pop();
				}

				//reset visit
				if (x_target > 0) {
					next_visit.push(pair<int, int>(y_target, x_target - 1));
				}
				if (x_target < N - 1) {
					next_visit.push(pair<int, int>(y_target, x_target + 1));
				}
				if (y_target > 0) {
					next_visit.push(pair<int, int>(y_target - 1, x_target));
				}
				if (y_target < N - 1) {
					next_visit.push(pair<int, int>(y_target + 1, x_target));
				}

				//cout << endl;
				for (int i = 0; i < N; i++)
				{
					for (int j = 0; j < N; j++)
					{
						area[i][j].second = 0;
						//cout << (int)area[i][j].first << ' ';
					}
					//cout << endl;
				}
				//cout << endl;
			}

			swap(visit, next_visit);
			dist++;
		}

		x_target = visit.front().second;
		y_target = visit.front().first;
		visit.pop();

		if (area[x_target][y_target].first > sz_level) continue;//not our target
		if (area[x_target][y_target].first == 9) continue;//shark cannot stop
		if (area[x_target][y_target].second != 0) continue;//already visited
		area[x_target][y_target].second = 1;

		if (area[x_target][y_target].first > 0 && area[x_target][y_target].first < sz_level)//shark can eat fish
		{
			food_pos.push(make_pair(x_target, y_target));//add to queue
		}

		if (x_target > 0) {
			next_visit.push(pair<int, int>(y_target, x_target - 1));
		}
		if (x_target < N - 1) {
			next_visit.push(pair<int, int>(y_target, x_target + 1));
		}
		if (y_target > 0) {
			next_visit.push(pair<int, int>(y_target - 1, x_target));
		}
		if (y_target < N - 1) {
			next_visit.push(pair<int, int>(y_target + 1, x_target));
		}
	}

	return eat_time;
}

int main()
{
	int N;
	cin >> N;

	vector<vector<pair<char, bool>>> area;

	int tmp;
	int shark_x, shark_y;

	for (int i = 0; i < N; i++)
	{
		vector<pair<char, bool>> tmpVec;
		for (int j = 0; j < N; j++)
		{
			cin >> tmp;
			tmpVec.push_back(pair<char, bool>(tmp, 0));
			if (tmp == 9) 
			{
				shark_x = i;
				shark_y = j;
			}
		}
		area.push_back(tmpVec);
	}

	int eat_cnt;
	eat_cnt = bfs_norm(area, shark_x, shark_y, N);

	cout << eat_cnt;

}
