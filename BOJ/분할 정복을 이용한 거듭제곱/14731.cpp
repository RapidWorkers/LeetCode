#include <iostream>

using namespace std;

//a^b mod m
unsigned long long pow_mod(unsigned long long a, unsigned long long b, unsigned long long mod)
{
	unsigned long long r = 1;
	a = a % mod;
	while (b)
	{
		if (b & 1) r = ((r % mod) * (a % mod)) % mod;
		b = b >> 1;
		a = ((a % mod) * (a % mod)) % mod;
	}

	return r;
}

int main()
{
	int n;
	cin >> n;
	unsigned long long a, b, m;
	m = 1000000007;

	unsigned long long r = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		
		if (b == 1) r += a;// (ax^1)' = a
		else if (b != 0)
		{
			r += ((((a % m) * (b % m)) % m ) * pow_mod(2, b - 1, m)) % m;
			r %= m;
		}
	}

	cout << r;
	return 0;

	
}
