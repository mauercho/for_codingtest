#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> person1 = {1,2,3,4,5};
    vector<int> person2 = {2,1,2,3,2,4,2,5};
    vector<int> person3 = {3,3,1,1,2,2,4,4,5,5};
    int idx = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    while (idx < answers.size()){
        if (person1[idx%person1.size()] == answers[idx]) cnt1++;
        if (person2[idx%person2.size()] == answers[idx]) cnt2++;
        if (person3[idx%person3.size()] == answers[idx]) cnt3++; 
        idx++;
    }
    
    int max_cnt = cnt1 > (cnt2 > cnt3? cnt2 : cnt3) ? cnt1 : (cnt2 > cnt3? cnt2 : cnt3);
    if (cnt1 == max_cnt) answer.push_back(1);
    if (cnt2 == max_cnt) answer.push_back(2);
    if (cnt3 == max_cnt) answer.push_back(3);
    return answer;
}