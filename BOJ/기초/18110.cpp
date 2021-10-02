#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	if (n == 0)
	{
		cout << 0;
		return 0;
	}

	double cut = round(n * 0.15);
	int cut_i = cut;

	vector<int> scores;

	int v;

	for (int i = 0; i < n; i++)
	{
		cin >> v;
		scores.push_back(v);
	}

	sort(scores.begin(), scores.end());
	
	int tot = 0;
	for (int i = cut_i; i < n - cut_i; i++)
	{
		tot += scores[i];
	}

	double avg = round(tot / (double)(n - 2 * cut_i));
	cout << avg << endl;

}
