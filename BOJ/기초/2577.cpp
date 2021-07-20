#include <iostream>
using namespace std;

int main() {
	int a, b, c, tmp, remain;
	int nList[10] = { 0 };
	cin >> a >> b >> c;

	tmp = a * b * c;

	while (tmp != 0) {
		remain = tmp % 10;
		nList[remain]++;
		tmp /= 10;
	}

	for (int i = 0; i < 10; i++)
		cout << nList[i] << endl;
}