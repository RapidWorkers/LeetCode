#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//Fast query/modify from codeforces http://codeforces.com/blog/entry/18051
void build(vector<int>& t, int n) {  // build the tree
	for (int i = n - 1; i > 0; --i) t[i] = (t[i << 1] > t[i << 1 | 1]) ? t[i << 1 | 1] : t[i << 1];
}

int query(vector<int>& t, int n, int l, int r) {  // sum on interval [l, r)
	int res = 1000000001;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) { res = (res < t[l]) ? res : t[l]; l++; }
		if (r & 1) { --r; res = (res < t[r]) ? res : t[r]; }
	}
	return res;
}

void modify(vector<int>& t, int n, int p, int value) {  // set value at position p
	for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = (t[p] > t[p ^ 1]) ? t[p ^ 1] : t[p];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int h = ceil(log2(N));
	int szTree = (1 << (h + 1));
	vector<int> segTree(szTree, 1000000001);

	int val;
	for (int i = 0; i < N; i++)//O(n)
	{
		cin >> val;
		segTree[(szTree >> 1) +i] = val;
	}
	
	build(segTree, szTree >> 1);

	for (int i = 0; i < M; i++)//O(n)
	{
		int a, b;
		cin >> a >> b;
		cout << query(segTree, szTree >> 1, a - 1, b) << '\n';
	}

	return 0;
}
