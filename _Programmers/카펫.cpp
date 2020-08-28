#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b){
    return a>b;
}

vector<int> solution(int brown, int yellow) {
    int w, h;
    vector<int> answer;
    
    for(w = 1; w < (brown - 4) / 2; w++){
        h = (brown - 4) / 2 - w;
        if(w * h == yellow){
            answer.push_back(w + 2);
            answer.push_back(h + 2);
            break;
        }
    }
    
    sort(answer.begin(), answer.end(), comp);
    return answer;
}