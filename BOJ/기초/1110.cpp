#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, c = 0;
	cin >> n;
	int a=n;

	do {
		int i = n % 10;
		int j = n / 10;
		int k = (i + j)%10;
		n = i * 10 + k;
		c++;
	} while (a != n);

	cout << c;
	
}