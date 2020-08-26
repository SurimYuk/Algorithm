//초등학생 때 풀던 문제를 생각하자.

#include <string>
#include <vector>
#define MAX 101

using namespace std;

int map[MAX][MAX];
int result[MAX][MAX];

int solution(int m, int n, vector<vector<int>> puddles) {
    for(int i = 0; i<puddles.size(); i++) map[puddles[i][1]][puddles[i][0]] = 1;
    
    result[1][0] = 1;
    for(int i = 1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(map[i][j]==1) result[i][j]=0;
            else result[i][j] = (result[i][j-1]+result[i-1][j])%1000000007;
        }
    }
    
    return result[n][m];
}