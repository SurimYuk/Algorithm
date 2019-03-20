#include <stdio.h>

int main(void) {
	int min, index, temp;
	int arr[10] = { 5,3,8,7,2,10,1,9,4,6 };

	for (int i = 0; i < 10; i++) {
		min = 99999;
		for (int j = i; j < 10; j++) {
			if (min > arr[j]) {
				min = arr[j];
				index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}