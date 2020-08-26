/*
N이 2개 사용 되는 경우는 N이 1개 사용되는 경우 + N이 1개 사용 되는 경우
N이 3개 사용 되는 경우는 (N=1)+(N=2), (N=2)+(N=1)
N이 6개 사용 되는 경우는:
6=1+5
6=2+4
6=3+3
6=4+2
6=5+1
*/

#include <string>
#include <vector>
#include <set>
#define MAX 8

using namespace std;

set<int> v[MAX];

int solution(int N, int number) {
    int base = 0;
    for(int i = 0; i<MAX; i++){
        base = base*10 + 1;
        v[i].insert(N*base);
    }
    
    for(int i = 1; i<MAX; i++){
        for(int j = 0; j<i; j++){
            for(auto op1:v[j]){
                for(auto op2:v[i-j-1]){
                    v[i].insert(op1+op2);
                    v[i].insert(op1*op2);
                    if(op1 > op2) v[i].insert(op1-op2);
                    if(op2 != 0) v[i].insert(op1/op2);
                }
            }
        }
        if(v[i].count(number)>0){
            return i+1;
        }
    }
    
    return -1;
}