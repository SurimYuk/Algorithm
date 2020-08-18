#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> m;
int solution(vector<vector<string>> clothes) {
    for(int i = 0; i < clothes.size(); i++) m[clothes[i][1]]++;
    
    int answer = 1;
    //for(pair<string,int> item: m) answer *= (item.second + 1);
    for(auto item: m) answer *= (item.second + 1); //(선택할 수 있는 항목 수(item.second) + 항목 중에서 아무것도 선택하지 않았을 경우(1))
    
    return answer - 1; //모든 항목이 선택되지 않았을 경우
}