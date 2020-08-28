#include <iostream>
#include <algorithm>
#define MAX 5000001
using namespace std;
long long arr[MAX];
int main(void) {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	cout << arr[k - 1];
	return 0;
}