#include <iostream>
using namespace std;
int arr[101][11];
int main(void) {
	for (int i = 1; i <= 9; i++) arr[1][i] = 1;
	for (int i = 2; i <= 100; i++) {
		for (int j = 1; j <= 9; j++) {
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % 1000000000;
		}
		arr[i][0] = arr[i - 1][1];
	}
	int n, sum = 0;
	cin >> n;
	for (int i = 0; i <= 9; i++) {
		sum += arr[n][i];
		sum = sum % 1000000000;
	}
	cout << sum;
	return 0;
}