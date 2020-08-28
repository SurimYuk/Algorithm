#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;
int arr[MAX];
int dp[MAX];
int main(void) {
	int n; 
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(arr[0] + arr[2], arr[2] + arr[1]);
	dp[2] = max(dp[2], dp[1]);
	for (int i = 3; i < n; i++) {
		dp[i] = max(arr[i] + arr[i - 1] + dp[i - 3], arr[i] + dp[i - 2]);
		dp[i] = max(dp[i], dp[i - 1]);
	}
	cout << dp[n - 1];
	return 0;
}