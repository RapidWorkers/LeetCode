#include <iostream>
using namespace std;

int main() {
	int num;
    cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> num;
	for (int i = num; i > 0; i--)
		cout << i << '\n';
}