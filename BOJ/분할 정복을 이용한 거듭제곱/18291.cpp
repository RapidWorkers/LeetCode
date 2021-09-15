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

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unsigned long long b, m;
	m = 1000000007;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> b;
		if (b == 1 || b == 2) cout << 1 << '\n';
		else cout << pow_mod(2, b - 2, m) << '\n';
	}

	return 0;

}
