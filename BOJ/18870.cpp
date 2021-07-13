#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> pos;
	vector<int> pos_compressed;

	for (int i = 0; i < N; i++)
	{
		int in;
		cin >> in;
		pos.push_back(in);
	}

	pos_compressed = pos;
	sort(pos_compressed.begin(), pos_compressed.end());
	pos_compressed.erase(unique(pos_compressed.begin(), pos_compressed.end()), pos_compressed.end());

	for (auto v : pos)
	{
		cout << lower_bound(pos_compressed.begin(), pos_compressed.end(), v) - pos_compressed.begin() << ' ';
	}

	return 0;

}
