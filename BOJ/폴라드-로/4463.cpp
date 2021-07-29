#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <set>
#include <algorithm>
#include <random>

using namespace std;

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

int main()
{
	vector<long long> fibo_precalc = { 0, 1 };

	for (int i = 2; i < 93; i++)
	{
		fibo_precalc.push_back(fibo_precalc[i - 1] + fibo_precalc[i - 2]);
	}

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	std::random_device rd;
	std::mt19937 gen(rd());

	while (true)
	{
		long long A, B;
		cin >> hex >> A >> hex >> B;

		if (cin.fail() || A >= B) return 0;

		cout << "Range " << A << " to " << B << ":\n";

		int start = 0;
		for (; start < fibo_precalc.size() && fibo_precalc[start] < A; start++);

		if (start >= fibo_precalc.size() || fibo_precalc[start] > B)
		{
			cout << "No Fibonacci numbers in the range\n\n";
			continue;
		}

		for (int i = start; i < fibo_precalc.size() && fibo_precalc[i] <= B; i++)
		{
			if (fibo_precalc[i] == 0) cout << "Fib(" << i << ") = " << fibo_precalc[i] << ", lg does not exist\n";
			else cout << "Fib(" << i << ") = " << fibo_precalc[i] << ", lg is " << fixed << setprecision(6) << log2(fibo_precalc[i]) << '\n';
			if (fibo_precalc[i] == 0 || fibo_precalc[i] == 1)  cout << "No prime factors\n";
			else
			{
				if (isP(fibo_precalc[i]))
				{
					cout << "Prime factors: " << fibo_precalc[i] << '\n';
				}
				else
				{
					multiset<unsigned long long> divisors;
					queue<unsigned long long> decompose;
					decompose.push(fibo_precalc[i]);

					while (!decompose.empty())
					{
						unsigned long long a = decompose.front();
						decompose.pop();

						while (a > 1)
						{
							if (isP(a))
							{
								divisors.insert(a);
								break;
							}

							std::uniform_int_distribution<long long> dis(0, a - 1);

							long long d;
							while (true)
							{
								long long x = dis(gen), c = dis(gen);
								d = pollard(a, x, c);
								if (d != -1) //success
								{
									if (isP(d)) divisors.insert(d);
									else decompose.push(d);
									break;
								}
							}

							//divisors.insert(d);
							a /= d;
						}
					}
					cout << "Prime factors:";
					for (auto d : divisors) cout << ' ' << d;
					cout << '\n';
				}
			}
		}
		cout << '\n';
	}
	return 0;
}