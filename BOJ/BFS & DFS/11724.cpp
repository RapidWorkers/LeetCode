#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<set<int>> graph(N + 1);
	vector<int> bfs_visited(N + 1);

	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		graph[A].insert(B);
		graph[B].insert(A);
	}

	queue<int> bfsQ;
	int conComp = 0;

	for (int i = 0; i < N; i++) {
		if (bfs_visited[i + 1]) continue;
		bfsQ.push(i+1);
		while (!bfsQ.empty())
		{
			int current = bfsQ.front();
			bfsQ.pop();

			if (bfs_visited[current]) continue;
			bfs_visited[current] = true;

			for (auto net : graph[current])
			{
				bfsQ.push(net);
			}
		}
		conComp++;
	}

	cout << conComp << endl;

}
