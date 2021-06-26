#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs_norm(vector<vector<pair<char, bool>>>& area, int x, int y, int N)
{
	char target = area[x][y].first;
	queue<pair<int, int>> visited;

	visited.push(pair<int, int>(x, y));

	while (!visited.empty())
	{
		int x_target = visited.front().first;
		int y_target = visited.front().second;
		visited.pop();

		if (area[x_target][y_target].first != target) continue;//not our target
		if (area[x_target][y_target].second != 0) continue;//already visited
		area[x_target][y_target].second = 1;

		if (x_target > 0) {
			visited.push(pair<int, int>(x_target - 1, y_target));
		}
		if (x_target < N - 1) {
			visited.push(pair<int, int>(x_target + 1, y_target));
		}
		if (y_target > 0) {
			visited.push(pair<int, int>(x_target, y_target - 1));
		}
		if (y_target < N - 1) {
			visited.push(pair<int, int>(x_target, y_target + 1));
		}
	}
}

int main()
{
	int N;
	cin >> N;

	vector<vector<pair<char, bool>>> area;

	char tmp;
	for (int i = 0; i < N; i++)
	{
		vector<pair<char, bool>> tmpVec;
		for (int j = 0; j < N; j++)
		{
			cin >> tmp;
			tmpVec.push_back(pair<char, bool>(tmp, 0));
		}
		area.push_back(tmpVec);
	}

	int norm_cnt = 0;
	int disa_cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (area[i][j].second == 0) {//not visited
				bfs_norm(area, i, j, N);
				norm_cnt++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (area[i][j].first == 'G') area[i][j].first = 'R';
			area[i][j].second = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (area[i][j].second == 0) {//not visited
				bfs_norm(area, i, j, N);
				disa_cnt++;
			}
		}
	}

	cout << norm_cnt << ' ' << disa_cnt;

}
