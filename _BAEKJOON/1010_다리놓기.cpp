#include <iostream>
#define MAX 31
using namespace std;

int arr[MAX][MAX];

void combination() {
	for (int i = 0; i < 31; i++) {
		arr[i][i] = arr[i][0] = 1;
		for (int j = 1; j < i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
}

int main(void) {
	int t, n, m;;
	cin >> t;
	combination();
	while (t-- > 0) {
		cin >> n >> m;
		cout << arr[m][n] << endl;
	}
	return 0;
}