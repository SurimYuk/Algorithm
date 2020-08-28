#include <iostream>
#include <string>
#include <algorithm>
#define MAX 100001
using namespace std;
class Person {
public:
	string name;
	int kor;
	int eng;
	int math;
} arr[MAX];
bool compare_kor(const Person &a, const Person &b) {
	return a.kor > b.kor;
}
bool compare_eng(const Person &a, const Person &b) {
	return a.eng < b.eng;
}
bool compare_math(const Person &a, const Person &b) {
	return a.math > b.math;
}
bool compare_name(const Person &a, const Person &b) {
	return a.name < b.name;
}
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].name >> arr[i].kor >> arr[i].eng >> arr[i].math;
	}
	stable_sort(arr, arr + n, compare_name);
	stable_sort(arr, arr + n, compare_math);
	stable_sort(arr, arr + n, compare_eng);
	stable_sort(arr, arr + n, compare_kor);
	for (int i = 0; i < n; i++) {
		cout << arr[i].name << '\n';
	}
	return 0;
}