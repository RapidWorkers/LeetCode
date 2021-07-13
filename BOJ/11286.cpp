#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mHeap;

	int N;
	cin >> N;

	int CMD;
	for (int i = 0; i < N; i++)
	{
		cin >> CMD;
		if (CMD == 0)
		{
			if (mHeap.empty()) cout << 0 << '\n';
			else
			{
				cout << mHeap.top().second << '\n';
				mHeap.pop();
			}
		}
		else
		{
			mHeap.push(make_pair(abs(CMD), CMD));
		}
	}

	return 0;
}
