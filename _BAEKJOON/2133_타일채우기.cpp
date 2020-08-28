#include <iostream>
#define MAX 31
using namespace std;
int arr[MAX];
int main(void) {
	int n;
	cin >> n;
	arr[0] = 1;
	arr[2] = 3;
	for (int i = 4; i <= n; i += 2) {
		arr[i] += 3 * arr[i - 2];
		for (int j = i - 4; j >= 0; j -= 2) {
			arr[i] += 2 * arr[j];
		}
	}
	cout << arr[n];
	return 0;
}