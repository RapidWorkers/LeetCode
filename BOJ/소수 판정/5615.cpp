#include <iostream>
#include <array>
#include <vector>

using namespace std;

//fast modulo-power algorithm
unsigned long long pow_mod(unsigned long long a, unsigned long long b, unsigned long long mod)
{
	long long r = 1;
	a = a % mod;
	while (b)
	{
		if (b & 1) r = ((r % mod) * (a % mod)) % mod;
		b = b >> 1;
		a = (a * a) % mod;
	}

	return r;
}


//miller-rabin test
bool isP(unsigned long long n)
{
	vector<int> testArr = { 2, 3, 5, 7, 11};//from wikipedia

	bool prime = false;

	for (int a : testArr)
	{
		unsigned long long k = n - 1;
		if (a >= n) break;

		while (true)
		{
			unsigned long long tmp = pow_mod(a, k, n);
			if (tmp == n - 1)
			{
				prime = true;
				break;
			}
			if (k % 2)
			{
				if (tmp == 1) prime = true;
				else return false;

				break;
			}
			k = k >> 1;
		}
		
	}

	//cout << n << ' ' << prime << endl;
	return prime;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		unsigned long long area;
		cin >> area;
		if (isP(area+area+1)) cnt++;
	}

	cout << cnt;
	return 0;
}
