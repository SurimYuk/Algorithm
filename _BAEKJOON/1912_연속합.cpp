#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
int arr[MAX], dp[MAX];
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}
	int maxNum = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		if (maxNum < dp[i]) maxNum = dp[i];
	}
	cout << maxNum;
	return 0;
}