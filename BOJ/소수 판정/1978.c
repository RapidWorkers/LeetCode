#include <iostream>
#include <vector>

using ull = unsigned long long;
using namespace std;

bool is_prime_traditional(ull num) {

	if (num == 1) return false;

	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

int main() {
	ull a, t, c = 0;
	vector<ull> b;

	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> t;
		b.push_back(t);
	}

	for (int i = 0; i < a; i++) {
		if (is_prime_traditional(b[i]))
			c++;
	}

	cout << c;
}