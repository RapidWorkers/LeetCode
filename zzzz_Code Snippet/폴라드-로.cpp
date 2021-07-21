//modulo multiplication
unsigned long long mulmod(unsigned long long a, unsigned long long b, unsigned long long mod)
{
	unsigned long long r = 0;
	while (b > 0)
	{
		if (b & 1) r = (r + a) % mod;
		a = (a * 2) % mod;
		b = b >> 1;
	}

	return r % mod;
}

//fast modulo-power algorithm a^b % mod
unsigned long long pow_mod(unsigned long long a, unsigned long long b, unsigned long long mod)
{
	long long r = 1;
	a = a % mod;
	while (b)
	{
		if (b & 1) r = mulmod(r, a, mod);
		b = b >> 1;
		a = mulmod(a, a, mod);
	}

	return r;
}

bool miller(unsigned long long n, int a)
{
	unsigned long long k = n - 1;

	if (n % a == 0) return false;

	while (true)
	{
		unsigned long long tmp = pow_mod(a, k, n);
		if (tmp == n - 1) return true;
		if (k % 2) return tmp == 1;
		k = k >> 1;
	}
}

//miller-rabin test
bool isP(unsigned long long n)
{
	vector<int> testArr = { 2, 3, 5, 7, 11 , 13, 17, 19, 23, 29, 31, 37 };//from wikipedia

	for (int a : testArr)
	{
		if (a >= n) break;
		if (!miller(n, a)) return false;
	}

	//cout << n << ' ' << prime << endl;
	return true;
}

unsigned long long gcd(unsigned long long A, unsigned long long B)
{
	//Euclidian algorithm
	unsigned long long tmp;
	if (B > A)
	{
		tmp = A;
		A = B;
		B = tmp;
	}
	while (B)
	{
		tmp = A % B;
		A = B;
		B = tmp;
	}

	return A;
}

//x: [0, a), c: [0, a)
unsigned long long g(unsigned long long x, unsigned long long n, unsigned long long c)
{
	return (mulmod(x, x, n) + c % n) % n;
}

long long pollard(unsigned long long n, long long x, long long c)
{
	long long y = x, d = 1;

	if (n == 4) return 2;

	while (d == 1)
	{
		x = g(x, n, c);
		y = g(g(y, n, c), n, c);
		d = gcd(abs(x - y), n);
	}

	if (d == n) return -1;
	else return d;

}
