#include <iostream>
#include <vector>

using namespace std;

int main()
{

	ios::sync_with_stdio(false);
	cout.tie(NULL);

	vector<int> tbl_0;
	vector<int> tbl_1;

	tbl_0.push_back(1);
	tbl_1.push_back(0);
	
	tbl_0.push_back(0);
	tbl_1.push_back(1);

	for (int i = 2; i <= 40; i++)
	{
		int cur0 = tbl_0[i - 1] + tbl_0[i - 2];
		int cur1 = tbl_1[i - 1] + tbl_1[i - 2];
		tbl_0.push_back(cur0);
		tbl_1.push_back(cur1);
	}

	int N;
	cin >> N;

	int INPUT;
	for (int i = 0; i < N; i++)
	{
		cin >> INPUT;
		cout << tbl_0[INPUT] << ' ' << tbl_1[INPUT] << '\n';
	}
}
