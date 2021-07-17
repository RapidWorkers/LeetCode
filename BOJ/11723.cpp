#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int buffer = 0;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string cmd;
		int param;

		cin >> cmd;

		if (cmd == "add")
		{
			cin >> param;
			param--;
			buffer = buffer | (1 << param);
		}
		else if (cmd == "remove")
		{
			cin >> param;
			param--;
			if (buffer & (1 << param)) buffer = buffer ^ (1 << param);
		}
		else if (cmd == "check")
		{
			cin >> param;
			param--;
			if (buffer & (1 << param)) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (cmd == "toggle")
		{
			cin >> param;
			param--;
			buffer = buffer ^ (1 << param);
		}
		else if (cmd == "all")
		{
			buffer = 0b11111111111111111111;
		}
		else if (cmd == "empty")
		{
			buffer = 0;
		}
	}

	return 0;
}
