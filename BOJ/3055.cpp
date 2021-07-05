#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs_norm(vector<vector<pair<char, bool>>>& area, int x, int y, int N, int M, vector<pair<int, int>> &water)
{

	queue<pair<int, int>> visit;
	queue<pair<int, int>> next_visit;

	next_visit.push(pair<int, int>(x, y));

	int dist = 0;

	while (!visit.empty() || !next_visit.empty())
	{

		if (visit.empty())
		{
			int waterCnt = water.size();//미리 지정 필요, 변동 예정이기 때문
			for (int i = 0; i < waterCnt; i++)
			{
				int waterX = water[i].first;
				int waterY = water[i].second;

				if (water[i].first > 0) {
					if (area[waterX - 1][waterY].first == '.' || area[waterX - 1][waterY].first == 'S')
					{
						area[waterX - 1][waterY].first = '*';
						water.push_back(make_pair(waterX - 1, waterY));
					}
				}
				if (water[i].first < N - 1) {
					if (area[waterX + 1][waterY].first == '.' || area[waterX + 1][waterY].first == 'S') {
						area[waterX + 1][waterY].first = '*';
						water.push_back(make_pair(waterX + 1, waterY));
					}
				}
				if (water[i].second > 0) {
					if (area[waterX][waterY - 1].first == '.' || area[waterX][waterY - 1].first == 'S') {
						area[waterX][waterY - 1].first = '*';
						water.push_back(make_pair(waterX, waterY - 1));
					}
				}
				if (water[i].second < M - 1) {
					if (area[waterX][waterY + 1].first == '.' || area[waterX][waterY + 1].first == 'S')
					{
						area[waterX][waterY + 1].first = '*';
						water.push_back(make_pair(waterX, waterY + 1));
					}
				}

			}
			swap(visit, next_visit);
			dist++;
		}

		int x_target = visit.front().first;
		int y_target = visit.front().second;

		if (area[x_target][y_target].first == 'D') return dist;

		visit.pop();

		if (area[x_target][y_target].second != 0) continue;//already visited
		area[x_target][y_target].second = 1;
		if (area[x_target][y_target].first == 'X') continue;//cannot move to stone

		if (x_target > 0) {
			if (area[x_target - 1][y_target].first == '.' || area[x_target - 1][y_target].first == 'D')
			{
				next_visit.push(pair<int, int>(x_target - 1, y_target));
			}
		}
		if (x_target < N - 1) {
			if (area[x_target + 1][y_target].first == '.' || area[x_target + 1][y_target].first == 'D')
			{
				next_visit.push(pair<int, int>(x_target + 1, y_target));
			}
		}
		if (y_target > 0) {
			if (area[x_target][y_target - 1].first == '.' || area[x_target][y_target - 1].first == 'D')
			{
				next_visit.push(pair<int, int>(x_target, y_target - 1));
			}
		}
		if (y_target < M - 1) {
			if (area[x_target][y_target + 1].first == '.' || area[x_target][y_target + 1].first == 'D')
			{
				next_visit.push(pair<int, int>(x_target, y_target + 1));
			}
		}
	}

	return -1;
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<pair<char, bool>>> area;
	vector<pair<int, int>> water;

	int startX = 0, startY = 0;

	char tmp;
	for (int i = 0; i < N; i++)
	{
		vector<pair<char, bool>> tmpVec;
		for (int j = 0; j < M; j++)
		{
			cin >> tmp;
			if (tmp == 'S') 
			{
				startX = i;
				startY = j;
			}
			else if (tmp == '*')
			{
				water.push_back(make_pair(i, j));
			}
			tmpVec.push_back(pair<char, bool>(tmp, 0));
		}
		area.push_back(tmpVec);
	}

	int result = bfs_norm(area, startX, startY, N, M, water);

	if (result > 0) cout << result - 1;
	else cout << "KAKTUS";

	return 0;
}
