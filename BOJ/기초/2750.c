#include <stdio.h>
#define TEST_CASE_SIZE 1000

void selection_sort(int[], int);

inline void swap(int* a, int* b);//inline, for increasing speed of function call

int main() {
	int count;
	int selSortArray[TEST_CASE_SIZE];

	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		scanf("%d", selSortArray + i);
	}

	selection_sort(selSortArray, count);
	for (int i = 0; i < count; i++)
		printf("%d\n", selSortArray[i]);
}

void selection_sort(int numArr[], int size) {
	for (int i = 0; i < size; i++) {
		int* min = numArr + i;
		for (int j = i + 1; j < size; j++) {
			//find the smallest value
			min = (*min < *(numArr + j)) ? min : numArr + j;
		}
		//and swap current array with min value
		swap(min, numArr + i);
	}
	return;
}

inline void swap(int* a, int* b) {//inline은 알 필요는 없다.
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}