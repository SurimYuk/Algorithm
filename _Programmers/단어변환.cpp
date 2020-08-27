#include <string>
#include <vector>

using namespace std;

int visited[50];
int answer = 51;

int checkDifference(string a, string b){
    int cnt = 0;
    for(int i = 0; i<a.length(); i++){
        if(a[i] != b[i]) cnt++;
    }
    return cnt;
}

void dfs(vector<string> words, string now, string target, int cnt){
    if(now == target){
        answer = min(answer, cnt);
        return;
    }
    
    for(int i = 0; i<words.size(); i++){
        if(!visited[i]){
            if(checkDifference(now, words[i]) == 1){
                visited[i] = 1;
                dfs(words, words[i], target, cnt+1);
                visited[i] = 0;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    dfs(words, begin, target, 0);
    
    if(answer == 51) return 0;
    return answer;
}