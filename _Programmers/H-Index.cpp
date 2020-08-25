/*
citations=[66,31]인 경우에는 2가 결과로 나와야 한다.
인용된 횟수보다 인용된 논문의 수의 집중하자.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b){
    return a>b;
}

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), comp);
    
    int i = 0;
    for(i = 0; i<citations.size(); i++){
        if(i+1 >= citations[i]) break;
    }
        
    return i;
}