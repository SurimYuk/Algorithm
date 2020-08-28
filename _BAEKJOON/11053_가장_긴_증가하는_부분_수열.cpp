#include <iostream>
#define MAX 1001
using namespace std;

int arr[MAX];
int length[MAX];

int main(void) {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
		length[i] = 1;
	}

	for (int i = 1; i < num; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (length[i] < length[j] + 1) {
					 length[i] = length[j] + 1;
				}
			}
		}
	}

	int max = -1;
	for (int i = 0; i < num; i++) {
		if (max < length[i]) max = length[i];
	}
	cout << max;
	return 0;
}