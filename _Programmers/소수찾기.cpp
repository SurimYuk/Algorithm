#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 10000001

using namespace std;

int sieve[MAX];

void calculateSieve(){
    for(int i = 2; i<MAX; i++) sieve[i] = 1;
    for(int i = 2; i<MAX; i++){
        for(int j = i+i; j<MAX; j=j+i){
            sieve[j] = 0;    
        }
    }
}

bool comp(char a, char b){
    return a > b;
}

bool isNumberIncluded(int num, string numbers){
    string s_num = to_string(num);
    for(int i = 0; i<s_num.length(); i++){
        bool flag = false;
        for(int j = 0; j<numbers.length(); j++){
            if(numbers[j] == s_num[i]){
                flag = true;
                numbers[j] = ' ';
                break;
            }
        }
        if(!flag) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    calculateSieve();
    sort(numbers.begin(), numbers.end(), comp);
    for(int i = 0; i<=stoi(numbers); i++){
        if(sieve[i] == 1 && isNumberIncluded(i, numbers)) answer++;
    }
    
    return answer;
}