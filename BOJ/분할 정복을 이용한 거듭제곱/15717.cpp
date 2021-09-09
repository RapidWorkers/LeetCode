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
	unsigned long long b, m;
	m = 1000000007;
	cin >> b;

	if (b == 0) cout << 1;
	else cout << pow_mod(2, b-1, m);
	return 0;
}
