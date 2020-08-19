#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i = 0; i<prices.size(); i++){
        bool flag = false;
        for(int j = i+1; j<prices.size(); j++){
            if(prices[i]>prices[j]){
                answer.push_back(j-i);
                flag=true;
                break;
            }
            else if(i==prices.size()-1) answer.push_back(0);
            else continue;
        }
        if(!flag) answer.push_back(prices.size()-1-i);
        }
    return answer;
}