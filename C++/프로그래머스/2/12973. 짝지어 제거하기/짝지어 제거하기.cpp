#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> stk;
    
    for (int i = 0; i < s.size(); i++){
        char temp = s[i];
        if (stk.empty()){
            stk.push(temp);
        } else {
            if (stk.top() == temp) {
                stk.pop();
            } else {
                stk.push(temp);
            }
        }
    }
    if (stk.empty()) answer = 1;
    else answer = 0;
    return answer;
}