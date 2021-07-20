#include <iostream>

using namespace std;

int main()
{
	int N, S;
	cin >> N >> S;

	int* A;
	A = new int[N];

	int sum = 0;
	int len = 994949494;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		sum += A[i];
	}

	if (sum < S) {
		cout << 0;
		return 0;
	}


	sum = A[0];
	int start = 0;
	int last = 0;

	while (start <= last && last < N)
	{
		if (sum < S) //일단 조건 충족시까지 더한다
		{
			last++;  sum += A[last];//한칸 확장
		}
		else if (sum == S)
		{
			len = (len > last - start + 1) ? last - start + 1 : len;//길이 구하고
			last++;  sum += A[last];//한칸 확장
		}
		else
		{
			len = (len > last - start + 1) ? last - start + 1 : len;//길이 구하고
			sum -= A[start];//한칸 축소
			start++;
		}
	}

	cout << len;

	delete[] A;
	return 0;
}
