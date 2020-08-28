#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
class Point {
public:
	int x; 
	int y;
};
bool compare_x(const Point &a, const Point &b) {
	return a.x < b.x;
}
bool compare_y(const Point &a, const Point &b) {
	return a.y < b.y;
}
Point arr[MAX];
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i].x >> arr[i].y;
	stable_sort(arr, arr + n, compare_y);
	stable_sort(arr, arr + n, compare_x);
	for (int i = 0; i < n; i++) cout << arr[i].x << ' '<< arr[i].y << '\n';
	return 0;
}