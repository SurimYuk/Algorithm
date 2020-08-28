#include <iostream>
#include <stdio.h>
#define MAX 10001
using namespace std;
int arr[MAX];
int main(void) {
	int n, a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		arr[a]++;
	}
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j <= arr[i]; j++) {
			printf("%d\n", i);
		}
	}
	return 0;
}