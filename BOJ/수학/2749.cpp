#include <iostream>

using namespace std;

unsigned long long fibo(unsigned long long n, unsigned long long m) {
	if (n == 0) return 0;

	unsigned long long a = 0, b = 1;
	unsigned long long c;

	for (int i = 1; i < n; i++)
	{
		c = a + b;
		c %= m;
		a = b;
		b = c;
	}

	return b;
}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unsigned long long m;
	m = 1e6;

	unsigned long long n;
	cin >> n;

	//pisano period
	// let m = 10^k and k > 2 then pisano period is 15*10^k-1
	unsigned long long period = 15 * 1e5;

	cout << fibo(n % period, m) % m;

	return 0;

}
