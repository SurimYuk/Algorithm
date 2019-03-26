#include <stdio.h>
#define LEN 10

void quickSort(int *data, int start, int end);

int data[LEN] = { 1,10,5,8,7,6,4,3,2,9 };

int main(void) {
	quickSort(data, 0, LEN - 1);
	for (int i = 0; i < LEN; i++) printf("%d ", data[i]);

	return 0;
}

void quickSort(int *data, int start, int end) {
	if (start >= end) return; //정렬할 데이터가 하나인 경우

	int pivot = start;
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j) {
		while (data[i] <= data[pivot]) i++; //내림차순: data[i] >= data[pivot]
		while (data[j] >= data[pivot] && j > start) j--; //내림차순: data[j] <= data[pivot]
		if (i > j) { //엇갈림
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}