#include <vector>
#include <iostream>

using namespace std;

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

bool isP(unsigned long long n)
{
	vector<int> testArr = { 2, 3, 5, 7, 11 };

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
	while (true)
	{
		int a, b;
		cin >> a >> b;

		if (a == 0 && b == 0) return 0;
		if (isP(a)) cout << "no\n";//prime number is always not fake prime
		else {
			unsigned long long fermat = pow_mod(b, a, a);
			if (fermat == b) cout << "yes\n";//fake prime
			else cout << "no\n";//not passed fermat's little theorem
		}

	}
}
