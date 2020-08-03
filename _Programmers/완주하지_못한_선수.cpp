#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<string,int>> names;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i = 0; i<completion.size(); i++){
        if(participant[i].compare(completion[i])==0) continue;
        else{
            answer = participant[i];
            return answer;
        }
    }
    return participant[participant.size()-1];
}