#include <iostream>

using namespace std;

int main() {
	int m, d, r, s = 0;
	cin >> m >> d;
	for (int i = 1; i < m; i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			s += 31;
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			s += 30;
		else
			s += 28;
	}
	s += d - 1;
	r = s % 7;
	
	switch (r) {
	case 0:
		cout << "MON";
		break;
	case 1:
		cout << "TUE";
		break;
	case 2:
		cout << "WED";
		break;
	case 3:
		cout << "THU";
		break;
	case 4:
		cout << "FRI";
		break;
	case 5:
		cout << "SAT";
		break;
	case 6:
		cout << "SUN";
		break;
	}
}