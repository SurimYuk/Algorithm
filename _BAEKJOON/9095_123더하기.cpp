#include <iostream>
#define MAX 12
using namespace std;
int dp[MAX];
int main(void) {
	int t, n;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < MAX; i++) dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	cin >> t;
	while (t-- > 0) {
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}