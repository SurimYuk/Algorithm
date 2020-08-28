#include <queue>
#include <string>
#include <iostream>
using namespace std;
queue<int> q;
int main(void) {
	int n, num;
	string s;
	cin >> n;
	while (n-- > 0) {
		cin >> s;
		if (s == "push") {
			cin >> num;
			q.push(num);
		}
		else if (s == "pop") {
			if (!q.empty()) {
				cout << q.front() << '\n';
				q.pop();
			}
			else cout << -1 << '\n';
		}
		else if (s == "size") cout << q.size() << '\n';
		else if (s == "empty") {
			if (q.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (s == "front") {
			if (!q.empty()) cout << q.front() << '\n';
			else cout << -1 << '\n';
		}
		else {
			if (!q.empty()) cout << q.back() << '\n';
			else cout << -1 << '\n';
		}
	}
	return 0;
}