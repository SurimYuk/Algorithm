#include <stdio.h>
#include <algorithm>

int arr[1000001], n;

int main(void) {	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	
	std::sort(arr, arr + n); //O(N*logN)보장

	for (int i = 0; i < n; i++) printf("%d\n", arr[i]);

	return 0;
}

/*
//quick sort를 사용하는 경우에 최악의 케이스가 O(N^2)이 되어서 시간초과가 남. 테스트 케이스에 거의 정렬된 테스트 값이 있는 것 같음.
void quickSort(int *arr, int start, int end);
int arr[1000001];

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) printf("%d\n", arr[i]);

	return 0;
}

void quickSort(int *arr, int start, int end) {
	if (start >= end) return;
	
	int pivot = start;
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j) {
		while (arr[i] <= arr[pivot]) i++;
		while (arr[j] >= arr[pivot] && start < j) j--; //start < j: j가 pivot의 영역을 침범할 수 없도록 막는 역할
		if (j < i) {
			temp = arr[pivot];
			arr[pivot] = arr[j];
			arr[j] = temp;
		}
		else {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	quickSort(arr, start, j - 1);
	quickSort(arr, j + 1, end);
}*/