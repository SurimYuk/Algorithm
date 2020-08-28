#include <iostream>
using namespace std;
long long arr[91][2];
int main(void) {
	arr[1][0] = 0;
	arr[1][1] = 1;
	for (int i = 2; i <= 90; i++) {
		arr[i][0] = arr[i - 1][0] + arr[i - 1][1];
		arr[i][1] = arr[i - 1][0];
	}
	int n;
	cin >> n;
	cout << arr[n][0] + arr[n][1];
	return 0;
}