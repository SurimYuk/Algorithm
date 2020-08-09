/*#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set<string> s;

bool comp(string a, string b){
    return a.length() < b.length();
}
bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end(), comp);
    for(int i = 0; i < phone_book.size(); i++){
        for(auto it=s.begin(); it!=s.end(); it++){
            if(phone_book[i].find(*it) == 0) return false;
        }
        s.insert(phone_book[i]);
    }
    return true;
}*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> m;

bool solution(vector<string> phone_book) {
    for (int i = 0; i < phone_book.size(); i++) m.insert({ phone_book[i], 1 });

    for (string phone_number : phone_book) {
        string buf = "";
        for (int i = 0; i < phone_number.length(); i++) {
            buf += phone_number[i];
            if (m[buf] > 0 && buf != phone_number) return false;
        }
    }
    return true;
}