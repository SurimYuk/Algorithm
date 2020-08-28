#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<long long, int> m;
map<long long, int>::iterator it;
int main(void) {
	int n;
	long long num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		m[num]++;
	}
	int max = -1;
	long long maxNum = -1;
	for (it = m.begin(); it != m.end(); it++) {
		if (it->second > max) {
			max = it->second;
			maxNum = it->first;
		}
		else if (it->second == max) {
			maxNum = min(maxNum, it->first);
		}
	}
	cout << maxNum;
	return 0;
}