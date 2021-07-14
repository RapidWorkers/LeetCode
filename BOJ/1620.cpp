#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map<string, int> pwMap;
	vector<string> arrPk;

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string site;
		cin >> site;
		pwMap.insert(make_pair(site, i+1));
		arrPk.push_back(site);
	}

	for (int i = 0; i < M; i++)
	{
		string buff;
		cin >> buff;
		stringstream ss(buff);

		if (ss.peek() >= '0' && ss.peek() <= '9')
		{
			int num;
			ss >> num;
			cout << arrPk[num - 1] << '\n';
		}
		else
		{
			string site;
			ss >> site;
			cout << pwMap[site] << '\n';
		}
	}

	return 0;
}
