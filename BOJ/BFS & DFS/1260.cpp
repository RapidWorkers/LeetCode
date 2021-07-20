#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>

using namespace std;

void dfs(vector<set<int>>& graph, vector<int> &visited, int node)
{
	if (visited[node]) return;
	visited[node] = true;

	cout << node << ' ';
	for (auto it = graph[node].begin(); it != graph[node].end(); it++)
	{
		dfs(graph, visited, *it);
	}
	
}

int main()
{
	int N, M, V;
	cin >> N >> M >> V;

	vector<set<int>> graph(N+1);
	vector<int> bfs_visited(N+1);
	vector<int> dfs_visited(N+1);

	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		graph[A].insert(B);
		graph[B].insert(A);
	}

	dfs(graph, dfs_visited, V);
	cout << endl;

	queue<int> bfsQ;
	bfsQ.push(V);
	while (!bfsQ.empty())
	{
		int current = bfsQ.front();
		bfsQ.pop();

		if (bfs_visited[current]) continue;
		bfs_visited[current] = true;

		cout << current << ' ';

		for (auto net : graph[current])
		{
			bfsQ.push(net);
		}

	}

}
