/*
1. 숫자가 매우 커질 수 있으니 그냥 문자열로 처리하는 방법이 낫다.
2. 경우의 수를 이용해서 모든 숫자 조합을 파악하기에는 시간복잡도가 너무 크다.
O(n^min{k,n-k}) => 100억 번 연산 => 1초(1억 번 연산)안에 절대 안끝난다.
3. 숫자를 정렬해서 순서대로 string에 붙히는 방법이 좋겠다.
3-1. 숫자를 문자로 바꿔서 사전역순으로 정렬한 후에 순서대로 합친다.
    3+30=330
    30+3=303
    사전역순이라면 30이 먼저 오겠지만, 3+30이 30+3이 더 큰 문제가 발생한다.
3-2. string 형태의 a와 b를 비교한다고 할 때, a와 b 자체를 비교하는 것이 아니라, 
    a+b(3+30=330)와 b+a(30+3=303)를 비교해서 더 큰 수가 만들어 지는 경우로 정렬한다.
4. numbers = [0,0,0,0,0,0] 인 경우, s_numbers는 ["0","0","0","0","0","0"]이 된다.
    answer는 "000000"이 된다. 모두 0인 경우는 "000000"이 아닌 0으로 만들어 줘야한다.
    정렬하면서 0은 어떻게든 맨 뒤로 정렬되어 있을 것이다. 하지만 answer이 0으로 시작하는
    경우는 numbers가 0으로만 이루어져 있다는 것을 의미한다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string s1, string s2){
    return s1+s2 > s2+s1;
}
string solution(vector<int> numbers) {
    vector<string> s_numbers;
    for(int i = 0; i<numbers.size(); i++) s_numbers.push_back(to_string(numbers[i]));
    sort(s_numbers.begin(), s_numbers.end(), comp);
        
    string answer = "";
    for(int i = 0; i<s_numbers.size(); i++) answer+=s_numbers[i];
    
    if(answer[0]=='0') answer="0";
    return answer;
}