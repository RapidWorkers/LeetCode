#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int bfs_norm(vector<vector<pair<bool, bool>>>& area, int x, int y, int N, int M)
{

	queue<pair<int, int>> visit;
	queue<pair<int, int>> next_visit;

	next_visit.push(pair<int, int>(x, y));

	int dist = 0;

	while (!visit.empty() || !next_visit.empty())
	{

		if (visit.empty())
		{
			swap(visit, next_visit);
			dist++;
		}

		int x_target = visit.front().first;
		int y_target = visit.front().second;

		if (x_target == N - 1 && y_target == M - 1) return dist;

		visit.pop();

		if (area[x_target][y_target].second != 0) continue;//already visited
		area[x_target][y_target].second = 1;
		if (area[x_target][y_target].first != 1) continue;//cannot move

		if (x_target > 0) {
			next_visit.push(pair<int, int>(x_target - 1, y_target));
		}
		if (x_target < N - 1) {
			next_visit.push(pair<int, int>(x_target + 1, y_target));
		}
		if (y_target > 0) {
			next_visit.push(pair<int, int>(x_target, y_target - 1));
		}
		if (y_target < M - 1) {
			next_visit.push(pair<int, int>(x_target, y_target + 1));
		}
	}

	return -1;
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<pair<bool, bool>>> area;

	char tmp;
	for (int i = 0; i < N; i++)
	{
		vector<pair<bool, bool>> tmpVec;
		for (int j = 0; j < M; j++)
		{
			cin >> tmp;
			tmpVec.push_back(pair<bool, bool>(tmp - '0', 0));
		}
		area.push_back(tmpVec);
	}

	cout << bfs_norm(area, 0, 0, N, M) << endl;
}
