#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int bfs_norm(vector<vector<pair<int, bool>>>& area, int x, int y, int N, int M)
{
	queue<pair<int, int>> visited;

	visited.push(pair<int, int>(x, y));

	int apt_cnt = 0;

	while (!visited.empty())
	{
		int x_target = visited.front().first;
		int y_target = visited.front().second;
		visited.pop();

		if (area[x_target][y_target].second != 0) continue;//already visited
		area[x_target][y_target].second = 1;
		if (area[x_target][y_target].first != 1) continue;//no building
		apt_cnt++;

		if (x_target > 0) {
			visited.push(pair<int, int>(x_target - 1, y_target));
		}
		if (x_target < N - 1) {
			visited.push(pair<int, int>(x_target + 1, y_target));
		}
		if (y_target > 0) {
			visited.push(pair<int, int>(x_target, y_target - 1));
		}
		if (y_target < M - 1) {
			visited.push(pair<int, int>(x_target, y_target + 1));
		}
	}

	return apt_cnt;
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int M, N, K;
		cin >> M >> N >> K;
		char tmp;
		
		vector<vector<pair<int, bool>>> area(N, vector<pair<int, bool>>(M));
		for (int i = 0; i < K; i++)
		{
			int x, y;
			cin >> x >> y;
			area[y][x].first = 1;
		}


		int total_apts = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (area[i][j].second == 0 && area[i][j].first == 1) {//not visited
					bfs_norm(area, i, j, N, M);
					total_apts++;
				}
			}
		}

		cout << total_apts << endl;
	}
}
