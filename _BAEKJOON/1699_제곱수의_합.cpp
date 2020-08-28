#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
int arr[MAX];
int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
		for (int j = 2; j*j <= i; j++) {
			arr[i] = min(arr[i], arr[i - j * j] + 1);
		}
	}
	cout << arr[n];
	return 0;
}