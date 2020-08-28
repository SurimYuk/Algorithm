#include <iostream>
using namespace std;
int arr[1001];
int dp[1001];
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	for (int i = n - 2; i >= 0; i--) {
		for (int j = n - 1; i < j; j--) {
			if (arr[i] > arr[j] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	int max = -1;
	for (int i = 0; i < n; i++) {
		if (max < dp[i]) max = dp[i];
	}
	cout << max;
	return 0;
}