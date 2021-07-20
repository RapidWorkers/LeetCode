#include <iostream>
#include <vector>

using namespace std;

int checkNum(int n) {
	int res = 0;
	int diff;
	for (int i = 1; i <= n; i++) {
		if (i < 100) {
			res++;
			continue;
		}
		vector<int>digit;
		int tmp = i;
		while (tmp > 0) {
			digit.push_back(tmp % 10);
			tmp /= 10;
		}		
		for (int j = 1; j < digit.size(); j++) {
			if (j == 1) {
				diff = digit[1] - digit[0];
			} else {
				if (digit[j] - digit[j-1] != diff) {
					res -= 1;
					break;
				}
			}
		}
		res++;
	}
	return res;
}

int main() {
	int a;
	cin >> a;
	int res = checkNum(a);
	cout << res;
}