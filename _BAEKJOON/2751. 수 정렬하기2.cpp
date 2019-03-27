#include <stdio.h>
#include <algorithm>

int arr[1000001], n;

int main(void) {	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	
	std::sort(arr, arr + n); //O(N*logN)����

	for (int i = 0; i < n; i++) printf("%d\n", arr[i]);

	return 0;
}

/*
//quick sort�� ����ϴ� ��쿡 �־��� ���̽��� O(N^2)�� �Ǿ �ð��ʰ��� ��. �׽�Ʈ ���̽��� ���� ���ĵ� �׽�Ʈ ���� �ִ� �� ����.
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
		while (arr[j] >= arr[pivot] && start < j) j--; //start < j: j�� pivot�� ������ ħ���� �� ������ ���� ����
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