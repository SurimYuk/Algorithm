#include <iostream>
#include <string>
#define MAX 5001
using namespace std;
int dp[MAX];
int main(void) {
	string s;
	getline(cin, s);
	s = ' ' + s;
	dp[0] = 1;
	int n;
	for (int i = 1; i < s.length(); i++) {
		n = s[i] - '0';
		if (n >= 1 && n <= 9) {
			dp[i] += dp[i - 1];
			dp[i] %= 1000000;
		}
		if (s[i - 1] == '0') continue;
		n = stoi(s.substr(i - 1, 2));
		if (n >= 10 && n <= 26) {
			dp[i] += dp[i - 2];
			dp[i] %= 1000000;
		}
	}
	cout << dp[s.length() - 1];
	return 0;
}