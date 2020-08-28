#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int score[3];
int person1[5]={1,2,3,4,5};
int person2[8]={2,1,2,3,2,4,2,5};
int person3[10]={3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    for(int i = 0; i <answers.size(); i++){
        if(answers[i] == person1[i%5]) score[0]++;
        if(answers[i] == person2[i%8]) score[1]++;
        if(answers[i] == person3[i%10]) score[2]++;
    }
    
    int max = -1;
    for(int i = 0; i<3; i++){
        if(score[i]>max) max=score[i];
    }
    
    for(int i = 0; i<3; i++){
        if(score[i] == max) answer.push_back(i + 1);
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}