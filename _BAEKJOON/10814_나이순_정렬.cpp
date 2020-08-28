#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<pair<pair<int, int>, string>> v;
int main(void) {
	int n, a;
	string b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ {a, i}, b });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		cout << v[i].first.first << ' ' << v[i].second << '\n';
	}
	return 0;
}