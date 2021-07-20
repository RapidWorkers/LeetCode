//Segment tree and inversion counting

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

using namespace std;

//Fast query/modify from codeforces http://codeforces.com/blog/entry/18051
int query(vector<int>& t, int n, int l, int r) {  // sum on interval [l, r)
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res += t[l++];
		if (r & 1) res += t[--r];
	}
	return res;
}

void modify(vector<int>& t, int n, int p, int value) {  // set value at position p
	for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
}


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> graph;

	int h = ceil(log2(N));
	int szTree = (1 << (h + 1));
	vector<int> segTree(szTree);

	int from, to;
	for (int i = 0; i < M; i++)//O(n)
	{
		cin >> to >> from;
		graph.push_back(make_pair(N - from, N - to));
	}

	sort(graph.rbegin(), graph.rend());

	long long crossed = 0;
	for (int i = 0; i < M; i++)
	{
		int curIdx = graph[i].second;//get value
		crossed += query(segTree, szTree >> 1, 0, curIdx);
		modify(segTree, szTree >> 1, curIdx, query(segTree, szTree >> 1, curIdx, curIdx+1)+1);
	}

	cout << crossed;

	return 0;

}
