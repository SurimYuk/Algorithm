#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v[20001];
vector<int> visited(20001, 0);
vector<int> dist(20001, 0);

void bfs(int x){
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    dist[x] = 0;
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(int i = 0; i<v[front].size(); i++){
            int y = v[front][i];
            if(!visited[y]) {
                visited[y] = 1;
                dist[y] = dist[front] + 1;
                q.push(y);
            }
        }
    }
}

bool comp(int a, int b){
    return a>b;
}

int solution(int n, vector<vector<int>> edge) {
    for(int i = 0; i < edge.size(); i++){
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    
    bfs(1);
    sort(dist.begin(), dist.end(),comp);
    
    int answer = 0;
    for(int i = 0; i<n; i++){
        if(dist[i] == dist[0]) answer++;
    } 
    
    return answer;
}