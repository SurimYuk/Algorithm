//union find
/*
#include <string>
#include <vector>
#include <set>

using namespace std;

int getParent(int parent[], int x){
    if(parent[x] == x) return x;
    return parent[x]=getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a<b) parent[b] = a;
    else parent[a] = b;
}

int solution(int n, vector<vector<int>> computers) {
    int parent[201]={0,};
    for(int i=0; i<n; i++) parent[i]=i;
    
    for(int i = 0; i<computers.size(); i++){
        for(int j = 0; j<computers[i].size(); j++){
            if(computers[i][j] == 1){
                unionParent(parent, i, j);
            }
        }
    }
    
    set<int> s;
    for(int i = 0; i<n; i++) s.insert(getParent(parent, parent[i]));
    return s.size();
}
*/

//dfs
/*
#include <string>
#include <vector>

using namespace std;

int visited[201];

void dfs(vector<vector<int>> computers, int x){
    if(visited[x]) return;
    visited[x] = 1;
    
    for(int i = 0; i<computers[x].size(); i++){
        if(computers[x][i] == 1) dfs(computers, i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i<computers.size(); i++){
        for(int j = 0; j<computers[i].size(); j++){
            if(computers[i][j] == 1 && !visited[i]) {
                answer++;
                dfs(computers, i);
            }
        }
    }
    
    return answer;
}
*/

//bfs
#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[201];

void bfs(vector<vector<int>> computers, int x){
    queue<int> q;
    q.push(x);
    visited[x]=1;
    
    while(!q.empty()){
        int a = q.front();
        q.pop();
        
        for(int i = 0; i<computers[a].size(); i++){
            if(computers[a][i] == 1 && !visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    /*
    for(int i = 0; i<computers.size(); i++){
        for(int j = 0; j<computers[i].size(); j++){
            if(!visited[i] && computers[i][j] == 1) {
                answer++;
                bfs(computers, i);
            }
        }
    }
    */

    for (int i = 0; i < computers.size(); i++) {
        if (!visited[i]) {
            answer++;
            bfs(computers, i);
        }
    }
    
    return answer;
}