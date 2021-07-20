#include <iostream>
using namespace std;

int main() {
	int a;
	cin >> a;

	for (int i = 1; i <= a; i++) {
		for (int j = a; j !=0; j--) {
			if (j>i)
				cout << " ";
			else
				cout << "*";
		}
		cout << endl;
	}
}