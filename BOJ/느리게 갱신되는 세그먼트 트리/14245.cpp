#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void prop_lazy(vector<long long>& t, vector<long long>& lazy, long long node, long long start, long long end)
{
	if (lazy[node] != 0)//has lazy
	{
		if ((end - start + 1) & 1)//odd xor
		{
			t[node] ^= lazy[node];
		}
		//note that even numbers of xor is same as doing nothing
		
		if (start != end)//not leaf node
		{
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

long long sum(vector<long long>& t, vector<long long>& lazy, long long node, long long start, long long end, long long left, long long right)
{
	prop_lazy(t, lazy, node, start, end);

	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return t[node];
	return sum(t, lazy, node * 2, start, (start + end) / 2, left, right) ^ sum(t, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector<long long>& t, vector<long long>& lazy, long long node, long long start, long long end, long long left, long long right, long long diff)
{
	prop_lazy(t, lazy, node, start, end);

	if (left > end || right < start) return;//out of range

	if (left <= start && end <= right)//in range complete
	{
		if ((end - start + 1) & 1)//odd xor
		{
			t[node] ^= diff;
		}
		//note that even numbers of xor is same as doing nothing

		if (start != end)
		{
			lazy[node * 2] ^= diff;
			lazy[node * 2 + 1] ^= diff;
		}
		return;
	}

	update(t, lazy, node * 2, start, (start + end) / 2, left, right, diff);
	update(t, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
	t[node] = t[node * 2] ^ t[node * 2 + 1];
}

long long init(vector<long long>& a, vector<long long>& tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = a[start];
	}
	else {
		return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) ^ init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}



int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;

	vector<long long> a(N + 1);

	int h = ceil(log2(N));
	int szTree = (1 << (h + 1));
	vector<long long> segTree(szTree);
	vector<long long> lazy(szTree);

	long long val;
	for (int i = 0; i < N; i++)
	{
		cin >> val;
		a[i] = val;
	}

	init(a, segTree, 1, 0, N - 1);

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		long long a, b, c, d;
		cin >> a >> b;

		if (a == 1)//update
		{
			cin >> c >> d;
			update(segTree, lazy, 1, 1, N, b+1, c+1, d);
		}
		else//print
		{
			cout << sum(segTree, lazy, 1, 1, N, b+1, b+1) << '\n';
		}
	}

	return 0;

}