#include <stdio.h>

int sorted[8];

void merge(int arr[], int m, int middle, int n) {
	int i = m;
	int j = middle + 1;
	int k = m;

	while (i <= middle && j <= n) {
		if (arr[i] < arr[j]) {
			sorted[k] = arr[i];
			i++;
		}
		else {
			sorted[k] = arr[j];
			j++;
		}
		k++;
	}
	if (i > middle) {
		for (int b = j; b <= n; b++) {
			sorted[k] = arr[b];
			k++;
		}
	}
	else {
		for (int b = i; b <= middle; b++) {
			sorted[k] = arr[b];
			k++;
		}
	}

	for (int b = m; b <= n; b++) arr[b] = sorted[b];
}

void mergeSort(int arr[], int m, int n) {
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(arr, m, middle);
		mergeSort(arr, middle + 1, n);
		merge(arr, m, middle, n);
	}
	//else: 정렬할 원소의 개수가 1인 경우
}

int main(void) {
	int num = 8;
	int arr[8] = { 7,6,5,8,3,5,9,1 };
	mergeSort(arr, 0, num - 1);
	for (int i = 0; i < num; i++) printf("%d ", arr[i]);
	return 0;
}