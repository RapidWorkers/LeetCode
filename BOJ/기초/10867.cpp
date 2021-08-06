#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> arr;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int V;
		cin >> V;
		arr.push_back(V);
	}

	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()),arr.end());

	for (auto n : arr) cout << n << ' ';
}
