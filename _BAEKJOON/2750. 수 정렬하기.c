#include <stdio.h>

int main(void) {
	int arr[1001];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	int min = 1001;
	int index = 0;
	int temp;
	for (int i = 0; i < n; i++) {
		min = 1001;
		for (int j = i; j < n; j++) {
			if (arr[j] < min) {
				min = arr[j];
				index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
	for (int i = 0; i < n; i++) printf("%d\n", arr[i]);

	return 0;
}