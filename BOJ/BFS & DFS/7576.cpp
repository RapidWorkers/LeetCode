#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int bfs_norm(vector<vector<pair<int, bool>>>& area, int N, int M)
{

	queue<pair<int, int>> visit;
	queue<pair<int, int>> next_visit;

	int zeros = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (area[i][j].first == 1) next_visit.push(make_pair(i,j));
			if (area[i][j].first == 0) zeros++;

		}
	}

	int dist = -1;

	while (!visit.empty() || !next_visit.empty())
	{
		
		if (visit.empty())
		{
			swap(visit, next_visit);
			dist++;
		}

		int x_target = visit.front().first;
		int y_target = visit.front().second;

		//if (x_target == N - 1 && y_target == M - 1) return dist;

		visit.pop();

		if (area[x_target][y_target].second != 0) continue;//already visited
		area[x_target][y_target].second = 1;//set to visited
		if (area[x_target][y_target].first == -1) continue;//no tomato

		if (x_target > 0) {
			if (area[x_target - 1][y_target].first == 0) {
				next_visit.push(pair<int, int>(x_target - 1, y_target));
				area[x_target - 1][y_target].first = 1;
				zeros--;
			}
			if (area[x_target - 1][y_target].first == -1) area[x_target - 1][y_target].second = 1;
		}
		if (x_target < N - 1) {
			if (area[x_target + 1][y_target].first == 0) {
				next_visit.push(pair<int, int>(x_target + 1, y_target));
				area[x_target + 1][y_target].first = 1;
				zeros--;
			}
			if (area[x_target + 1][y_target].first == -1) area[x_target + 1][y_target].second = 1;
		}
		if (y_target > 0) {
			if (area[x_target][y_target - 1].first == 0) {
				next_visit.push(pair<int, int>(x_target, y_target - 1));
				area[x_target][y_target - 1].first = 1;
				zeros--;
			}
			if (area[x_target][y_target - 1].first == -1) area[x_target][y_target - 1].second = 1;
		}
		if (y_target < M - 1) {
			if (area[x_target][y_target + 1].first == 0) {
				next_visit.push(pair<int, int>(x_target, y_target + 1));
				area[x_target][y_target + 1].first = 1;
				zeros--;
			}
			if (area[x_target][y_target+1].first == -1) area[x_target][y_target + 1].second = 1;
		}
	}

	if (zeros) return -1;
	return dist;
}

int main()
{
	int N, M;
	cin >> M >> N;

	vector<vector<pair<int, bool>>> area;

	int tmp;
	for (int i = 0; i < N; i++)
	{
		vector<pair<int, bool>> tmpVec;
		for (int j = 0; j < M; j++)
		{
			cin >> tmp;
			tmpVec.push_back(pair<int, bool>(tmp, 0));
		}
		area.push_back(tmpVec);
	}

	cout << bfs_norm(area, N, M) << endl;
	return 0;
}
