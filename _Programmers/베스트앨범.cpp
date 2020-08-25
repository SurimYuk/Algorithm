#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

struct music{
    int id;
    int plays;
};

unordered_map<string, int> um;
vector<pair<string, int>> v;
unordered_map<string, vector<music>> info;

bool comp1(pair<string, int> p1, pair<string, int> p2){
    return p1.second > p2.second;
}

bool comp2(music m1, music m2){
    if(m1.plays == m2.plays) return m1.id<m2.id;
    else return m1.plays>m2.plays;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for(int i = 0; i<genres.size(); i++) {
        um[genres[i]] += plays[i];
        info[genres[i]].push_back({i, plays[i]});
    }
    for(auto m:um) v.push_back({m.first, m.second});
    sort(v.begin(), v.end(), comp1);
    
    for(int i = 0; i<v.size(); i++){
        sort(info[v[i].first].begin(), info[v[i].first].end(), comp2);
        for(int j=0; j<info[v[i].first].size() && j<2; j++){
            answer.push_back(info[v[i].first][j].id);
        }
    }
    
    return answer;
}