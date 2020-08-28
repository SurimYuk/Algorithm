#include <iostream>
#define MAX 201
int arr[MAX][MAX];
using namespace std;
int main(void) {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) arr[i][1] = 1;
	for (int i = 1; i <= k; i++) arr[1][i] = i;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]) % 1000000000;
		}
	}
	cout << arr[n][k];
	return 0;
}