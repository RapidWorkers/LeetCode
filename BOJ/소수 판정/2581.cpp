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
	ull a, b, s = 0, min = 0;

	cin >> a >> b;

	for (int i = a; i <= b; i++) {
		if (is_prime_traditional(i)) {
			if (!min) min = i;
			s += i;
		}
	}

	if(s)
		cout << s << endl << min;
	else cout << -1;
}