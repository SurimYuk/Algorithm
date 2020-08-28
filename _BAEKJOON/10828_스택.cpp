#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack<int> st;
int main(void) {
	ios_base::sync_with_stdio(false);
	int n, popNum, m;
	string s;
	cin >> n;
	while (n-- > 0) {
		cin >> s;
		if (s=="push") {
			cin >> m;
			st.push(m);
		}
		else if (s=="pop") {
			if (!st.empty()) {
				popNum = st.top();
				st.pop();
				cout << popNum << '\n';
			}
			else cout << -1 << '\n';
			
		}
		else if (s == "top") {
			if(!st.empty()) cout << st.top() << '\n';
			else cout << -1 << '\n';
		}
		else if (s=="size") cout << st.size() << '\n';
		else {
			if (st.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}
	return 0;
}