#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    if (ceil((double)a / 2) == ceil((double)b / 2)){
        return 1;
    } 
    while (a != b){
        answer += 1;
        a = ceil((double)a / 2);
        b = ceil((double)b / 2);
    }
    
    return answer;
}