#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
int arr[2][MAX];
int dp[2][MAX];
int main(void) {
	int t, n;
	cin >> t;
	while (t-- > 0) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}
		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];
		for (int j = 2; j <= n; j++) {
			dp[0][j] = max(dp[1][j - 1], dp[1][j - 2]) + arr[0][j];
			dp[1][j] = max(dp[0][j - 1], dp[0][j - 2]) + arr[1][j];
		}
		cout << max(dp[0][n], dp[1][n]) << endl;
	}
}