#include <iostream>
#define MAX 1001
using namespace std;

int arr[MAX];
int sum[MAX];

int main(void) {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
		sum[i] = arr[i];
	}
	int max = -1;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && sum[i]<sum[j]+arr[i]) {
				sum[i] = sum[j] + arr[i];
			}
		}
		if (max < sum[i]) max = sum[i];
	}
	
	cout << max;
	return 0;
}