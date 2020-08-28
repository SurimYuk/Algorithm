#include <iostream>
using namespace std;
int arr[1001][10];
int main(void) {
	for (int i = 0; i < 10; i++) arr[1][i] = 1;
	for (int i = 2; i < 1001; i++) {
		arr[i][0] = 1;
		for (int j = 1; j < 10; j++) {
			arr[i][j] = (arr[i][j - 1] + arr[i - 1][j]) % 10007;
		}
	}
	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < 10; i++) {
		sum += arr[n][i];
		sum %= 10007;
	}
	cout << sum;
	return 0;
}