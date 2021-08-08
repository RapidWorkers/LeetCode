#include <iostream>

using namespace std;

//a^b mod m
unsigned long long fastpow(unsigned long long a, unsigned long long b, unsigned long long m)
{

	if (b == 1) return a % m;
	unsigned long long tmp = fastpow(a, b / 2, m);

	if (b & 1) return ((tmp * tmp) % m * a) % m; 
	else return (tmp * tmp) % m;
}

int main()
{
	unsigned long long a, b, m;
	cin >> a >> b >> m;
	cout << fastpow(a, b, m);
	return 0;
}
