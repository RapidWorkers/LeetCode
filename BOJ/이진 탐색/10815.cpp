#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> nList;

	int N;
	cin >> N;

	int V;
	for (int i = 0; i < N; i++)
	{
		cin >> V;
		nList.push_back(V);
	}

	sort(nList.begin(), nList.end());

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> V;
		int idx = lower_bound(nList.begin(), nList.end(), V) - nList.begin();
		if (idx < nList.size() && nList[idx] == V) cout << "1 ";
		else cout << "0 ";
	}
}
