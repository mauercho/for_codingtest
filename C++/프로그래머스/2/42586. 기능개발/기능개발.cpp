#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for (int i = 0; i < progresses.size(); i++){
        if ((100 - progresses[i]) % speeds[i] == 0){
            q.push((100 - progresses[i]) / speeds[i]);
        } else {
            q.push((100 - progresses[i]) / speeds[i] + 1);
        }
    }
    int temp;
    while (!q.empty()){
        temp = q.front();
        int cnt = 0;
        while (!q.empty() && q.front() <= temp){
            q.pop();
            cnt++;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}