#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int bfs_norm(vector<vector<pair<bool, bool>>>& area, int x, int y, int N)
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
		if (y_target < N - 1) {
			visited.push(pair<int, int>(x_target, y_target + 1));
		}
	}

	return apt_cnt;
}

int main()
{
	int N;
	cin >> N;

	vector<vector<pair<bool, bool>>> area;
	multiset<int> apt;

	char tmp;
	for (int i = 0; i < N; i++)
	{
		vector<pair<bool, bool>> tmpVec;
		for (int j = 0; j < N; j++)
		{
			cin >> tmp;
			tmpVec.push_back(pair<bool, bool>(tmp - '0', 0));
		}
		area.push_back(tmpVec);
	}

	int total_apts = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (area[i][j].second == 0 && area[i][j].first == 1) {//not visited
				apt.insert(bfs_norm(area, i, j, N));
				total_apts++;
			}
		}
	}

	cout << total_apts << endl;
	for (int v : apt)
	{
		cout << v << endl;
	}

}
