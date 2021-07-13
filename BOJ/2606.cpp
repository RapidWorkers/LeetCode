#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> networks(N+1);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		networks[a].push_back(b);
		networks[b].push_back(a);
	}

	vector<int> visited(N);
	queue<int> toVisit;
	toVisit.push(1);

	int infected = -1;
	while (!toVisit.empty())
	{
		int current = toVisit.front();
		toVisit.pop();

		if (visited[current]) continue;
		visited[current] = true;
		infected++;

		for (auto net : networks[current])
		{
			toVisit.push(net);
		}
		
	}

	cout << infected << endl;

	return 0;
}
