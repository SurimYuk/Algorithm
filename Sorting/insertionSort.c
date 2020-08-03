#include <stdio.h>

int main(void) {
	int temp;
	int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };

	int j = 0;
	for (int i = 0; i < 9; i++) {
		j = i;
		while (arr[j] > arr[j + 1]) {
			temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
			j--;
		}
	}
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}