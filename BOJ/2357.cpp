#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//Fast query/modify from codeforces http://codeforces.com/blog/entry/18051
void buildMin(vector<int>& t, int n) {  // build the tree
	for (int i = n - 1; i > 0; --i) t[i] = (t[i << 1] > t[i << 1 | 1]) ? t[i << 1 | 1] : t[i << 1];
}

int queryMin(vector<int>& t, int n, int l, int r) {  // sum on interval [l, r)
	int res = 1000000001;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) { res = (res < t[l]) ? res : t[l]; l++; }
		if (r & 1) { --r; res = (res < t[r]) ? res : t[r]; }
	}
	return res;
}

void buildMax(vector<int>& t, int n) {  // build the tree
	for (int i = n - 1; i > 0; --i) t[i] = (t[i << 1] < t[i << 1 | 1]) ? t[i << 1 | 1] : t[i << 1];
}

int queryMax(vector<int>& t, int n, int l, int r) {  // sum on interval [l, r)
	int res = -1;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) { res = (res > t[l]) ? res : t[l]; l++; }
		if (r & 1) { --r; res = (res > t[r]) ? res : t[r]; }
	}
	return res;
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
	vector<int> segTreeMin(szTree, 1000000001);
	vector<int> segTreeMax(szTree, -1);

	int val;
	for (int i = 0; i < N; i++)//O(n)
	{
		cin >> val;
		segTreeMin[(szTree >> 1) +i] = val;
		segTreeMax[(szTree >> 1) +i] = val;
	}
	
	buildMin(segTreeMin, szTree >> 1);
	buildMax(segTreeMax, szTree >> 1);

	for (int i = 0; i < M; i++)//O(n)
	{
		int a, b;
		cin >> a >> b;
		cout << queryMin(segTreeMin, szTree >> 1, a - 1, b) << ' ';
		cout << queryMax(segTreeMax, szTree >> 1, a - 1, b) << '\n';
	}

	return 0;
}
