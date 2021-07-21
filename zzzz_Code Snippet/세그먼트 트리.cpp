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

	int h = ceil(log2(N));
	int szTree = (1 << (h + 1));
	vector<long long> segTree(szTree);