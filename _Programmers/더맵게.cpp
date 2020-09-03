/*
max heap이 기본이라서 scoville을 음수로 변환해서 처리했다.
[12,10,9,3,2,1] -> [-1,-2,-3,-9,-10,-12]
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for(int i = 0; i<scoville.size(); i++) pq.push(-scoville[i]);
    while(pq.top()*(-1) < K){
        if(pq.size() == 1) return -1;
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int newScoville = a+b*2;
        pq.push(newScoville);
        answer++;
    }
    
    return answer;
}