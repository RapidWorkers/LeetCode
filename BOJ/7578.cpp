//Segment tree and inversion counting

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

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

	int N;
	cin >> N;

	vector<pair<int, int>> runners(N);//value, idx
	vector<int> below(N);

	int h = ceil(log2(N));
	int szTree = (1 << (h + 1));
	vector<int> segTree(szTree);

	int val;
	for (int i = 0; i < N; i++)//O(n)
	{
		cin >> val;
		runners[i] = make_pair(val, N - i - 1);
	}

	sort(runners.begin(), runners.end());

	for (int i = 0; i < N; i++)//O(n)
	{
		cin >> val;
		below[i] = lower_bound(runners.begin(), runners.end(), pair<int, int>{val, 0}, [](pair<int, int> a, pair<int, int> b) -> bool {return a.first < b.first; })->second;
	}

	long long crossed = 0;
	for (int i = 0; i < N; i++)
	{
		int curIdx = below[i];//get value
		crossed += query(segTree, N, 0, curIdx);
		modify(segTree, N, curIdx, 1);
	}

	cout << crossed;

	return 0;

}
