#include <iostream>
int fibo(int n) {
	int a = 1, b = 1, tmp;
	for (int i = 1; i < n; i++) {//n-1�� �ݺ�
		tmp = b;
		b = a + b; //�Ǻ���ġ ������ ���� �� ���� ��
		a = tmp;
	}
	return b;//������ �� ��ȯ
}
int main() {
	int n;
	std::cin >> n;
	std::cout << fibo(n-1);
}