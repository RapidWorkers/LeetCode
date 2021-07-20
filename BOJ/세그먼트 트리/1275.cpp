//Basic Segment tree

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//Fast query/modify from codeforces http://codeforces.com/blog/entry/18051
long long query(vector<long long>& t, int n, int l, int r) {  // sum on interval [l, r)
	long long res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res += t[l++];
		if (r & 1) res += t[--r];
	}
	return res;
}

void modify(vector<long long>& t, int n, int p, long long value) {  // set value at position p
	for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
}

void build(vector<long long>& t, int n) {  // build the tree
	for (int i = n - 1; i > 0; --i) t[i] = t[i << 1] + t[i << 1 | 1];
}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, Q;
	cin >> N >> Q;

	int h = ceil(log2(N));
	int szTree = (1 << (h + 1));
	vector<long long> segTree(szTree);

	int val;
	for (int i = 0; i < N; i++)//O(n)
	{
		cin >> val;
		segTree[(szTree >> 1) + i] = val;
	}

	build(segTree, szTree >> 1);

	for (int i = 0; i < Q; i++)
	{
		long long x, y, a, b;
		cin >> x >> y >> a >> b;

		if (x > y) { int tmp = x; x = y; y = tmp;  }

		cout << query(segTree, szTree >> 1, x - 1, y) << '\n';
		modify(segTree, szTree >> 1, a - 1, b);

	}

	return 0;

}
