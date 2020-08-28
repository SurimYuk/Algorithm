#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;
int arr[MAX], dp[MAX];
int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], arr[j] + dp[i - j]);
		}
	}
	cout << dp[n];
	return 0;
}