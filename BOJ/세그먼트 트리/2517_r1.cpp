//Segment tree and inversion counting

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

//long long sum(vector<long long>& tree, int node, int start, int end, int left, int right)
//{
//	if (left > end || right < start) return 0;//out of range completely
//	if (left <= start && end <= right) return tree[node];
//	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
//}
//
//void update(vector<long long>& tree, int node, int start, int end, int index, long long diff)
//{
//	if (index < start || index > end) return;
//	tree[node] = tree[node] + diff;
//	if (start != end) {//not leaf node
//		update(tree, node * 2, start, (start + end) / 2, index, diff);//update left subtree
//		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);//update right subtree
//	}
//}

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

	int N;
	cin >> N;

	map<int, int, greater<int>> runners_idx;//key = input, val = id
	vector<int> runners;

	int h = ceil(log2(N));
	int szTree = (1 << (h + 1));
	vector<int> segTree(szTree);

	int val;
	for (int i = 0; i < N; i++)//O(n)
	{
		cin >> val;
		runners_idx.insert(make_pair(val, 0));
		runners.push_back(val);
	}

	int rank = 0;
	for (auto it = runners_idx.begin(); it != runners_idx.end(); it++)//O(nlogn)
	{
		it->second = rank++;
	}
	

	for (auto v : runners)//O(nlogn + nlogn)
	{
		int curIdx = runners_idx[v];//get id of value
		//int maxRank = sum(segTree, 1, 0, N - 1, 0, curIdx - 1) + 1;
		//update(segTree, 1, 0, N - 1, curIdx, 1);
		int maxRank = query(segTree, N, 0, curIdx) + 1;
		modify(segTree, N, curIdx, 1);

		cout << maxRank << '\n';
	}

	return 0;

}
