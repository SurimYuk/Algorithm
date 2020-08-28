#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
int visited[10001];

bool dfs(vector<vector<string>> tickets, string now, int cnt){
    answer.push_back(now);
    
    if(cnt == tickets.size()){
        return true;
    }
    
    for(int i = 0; i<tickets.size(); i++){
        if(tickets[i][0] == now && !visited[i]){
            visited[i] = 1;
            if(dfs(tickets, tickets[i][1], cnt+1)) return true;
            visited[i] = 0;
        }
    }
    
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    dfs(tickets, "ICN", 0);
    
    return answer;
}