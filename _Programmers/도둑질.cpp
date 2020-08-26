/*
dp1: 첫번째 집을 무조건 터는 경우
dp2: 마지막 집을 무조건 터는 경우
*/

#include <string>
#include <vector>
#define MAX 1000001

using namespace std;

int dp1[MAX], dp2[MAX];
int solution(vector<int> money) {    
    dp1[0] = money[0];
    dp1[1] = max(money[0], money[1]);
    
    dp2[0] = 0;
    dp2[1] = money[1];
    
    for(int i=2; i<money.size()-1; i++) dp1[i] = max(money[i]+dp1[i-2], dp1[i-1]);
    for(int i=2; i<money.size(); i++) dp2[i] = max(money[i]+dp2[i-2], dp2[i-1]);
    
    return max(dp1[money.size()-2], dp2[money.size()-1]);
}