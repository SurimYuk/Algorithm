#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct cmp{
    bool operator()(vector<int> a, vector<int> b){
        return a[1] > b[1]; 
        /*
        더 작은 값에 우선순위를 준다.(오름차순)
        a[1] > b[1]일 때 return true;
        */
    }    
};

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    
    int idx= 0, time = 0, answer = 0;
    while(idx<jobs.size() || !pq.empty()){
        if(idx<jobs.size() && jobs[idx][0]<=time) {
            pq.push(jobs[idx++]);
            continue;
        }
        if(!pq.empty()){
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else time = jobs[idx][0];
    }  
    
    return answer/jobs.size();
}