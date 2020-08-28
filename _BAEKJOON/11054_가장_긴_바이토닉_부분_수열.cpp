#include <iostream>
#define MAX 1001
using namespace std;
int arr[MAX], increase[MAX], decrease[MAX];
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		increase[i] = decrease[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && increase[j] + 1 > increase[i])
				increase[i] = increase[j] + 1;
		}
	}
	for (int i = n - 2; i >= 0; i--) {
		for (int j = n - 1; i < j; j--) {
			if (arr[i] > arr[j] && decrease[j] + 1 > decrease[i])
				decrease[i] = decrease[j] + 1;
		}
	}
	int max = -1, sum = 0;
	for (int i = 0; i < n; i++) {
		sum = increase[i] + decrease[i];
		if (max < sum) max = sum;
	}
	cout << max - 1;
	return 0;
}