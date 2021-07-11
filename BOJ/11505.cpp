//Basic Segment tree

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//Fast query/modify from codeforces http://codeforces.com/blog/entry/18051
long long query(vector<long long>& t, int n, int l, int r) {  // sum on interval [l, r)
	long long res = 1;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res = (res * t[l++]) % 1000000007;//modular arithmetic
		if (r & 1) res = (res * t[--r]) % 1000000007;//modular arithmetic
	}
	return res;
}

void modify(vector<long long>& t, int n, int p, long long value) {  // set value at position p
	for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = (t[p] * t[p ^ 1]) % 1000000007;//modular arithmetic
}

void build(vector<long long>& t, int n) {  // build the tree
	for (int i = n - 1; i > 0; --i) t[i] = (t[i << 1] * t[i << 1 | 1]) % 1000000007;//modular arithmetic
}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	int h = ceil(log2(N));
	int szTree = (1 << (h + 1));
	vector<long long> segTree(szTree, 1);//should be initialized with 1

	int val;
	for (int i = 0; i < N; i++)//O(n)
	{
		cin >> val;
		segTree[(szTree >> 1) + i] = val;
	}

	build(segTree, szTree >> 1);

	for (int i = 0; i < M + K; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;

		if (a == 1)//update
		{
			modify(segTree, szTree >> 1, b - 1, c);
		}
		else//print
		{
			cout << query(segTree, szTree >> 1, b - 1, c) << '\n';
		}
	}

	return 0;

}
