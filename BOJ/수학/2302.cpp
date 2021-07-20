#include <iostream>

using namespace std;

int fibo(int n);

int main() {
	int seat, ps_cnt, tmp, ps[40] = { 0 }, result = 1;

	cin >> seat >> ps_cnt;

	for (int i = 0; i < ps_cnt; i++) {
		cin >> tmp;
		ps[tmp - 1] = 1;
	}

	tmp = 0;

	for (int i = 0; i <= seat; i++) {
		if (i == seat) {
			result *= fibo(tmp);
			break;
		}
		if (ps[i]) {
			result *= fibo(tmp);
			tmp = 0;
		}
		else
			tmp++;
	}

	cout << result;
}

int fibo(int n) {
	int a = 1, b = 1, tmp;
	for (int i = 1; i < n; i++) {//n-1번 반복
		tmp = b;
		b = a + b; //피보나치 수열은 이전 두 값의 합
		a = tmp;
	}
	return b;//수열의 값 반환
}