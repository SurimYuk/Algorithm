#include <iostream>
#include <stack>
using namespace std;
stack<char> s;
int arr[100001], i, sum = 0;
int main(void) {
	char c;
	char temp;
	while (cin.get(c)) {
		if (c == '(') {
			s.push(c);
		}
		else {
			if (!s.empty()) {
				if (temp == '(') {
					s.pop();
					for (int j = 0; j < s.size(); j++) {
						arr[j]++;
					}
				}
				else {
					sum += arr[s.size() - 1] + 1;
					arr[s.size() - 1] = 0;
					s.pop();
				}
			}
			
		}
		temp = c;
		if (c == '\n') break;
	}
	cout << sum;
	return 0;
}