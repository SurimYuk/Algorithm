//원본 벡터를 건드리지 말기.

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> v = triangle;
    for(int i = 0; i<triangle.size()-1; i++){
        for(int j = 0; j<triangle[i].size(); j++){
            v[i+1][j]=max(v[i+1][j],v[i][j]+triangle[i+1][j]);
            v[i+1][j+1]=max(v[i+1][j+1], v[i][j]+triangle[i+1][j+1]);
        }
    }
    
    int index = triangle.size()-1;
    int answer = 0;
    for(int i = 0; i<triangle[index].size(); i++)
        answer = max(answer, v[index][i]);
    
    return answer;
}