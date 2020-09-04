#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    for(int i = 0; i<operations.size(); i++){
        if(operations[i].find("D 1") == 0){
            if(!dq.empty()) dq.pop_back();
        }
        else if(operations[i].find("D -1") == 0){
            if(!dq.empty()) dq.pop_front();
        }
        else{
            int num = stoi(operations[i].substr(2));
            dq.push_back(num);
            sort(dq.begin(), dq.end());
        }
    }
    if(dq.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(dq.back());
        answer.push_back(dq.front());    
    }
    
    return answer;
}