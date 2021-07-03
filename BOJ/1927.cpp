#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> mHeap;

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
				cout << mHeap.top() << '\n';
				mHeap.pop();
			}
		}
		else
		{
			mHeap.push(CMD);
		}
	}

	return 0;
}
