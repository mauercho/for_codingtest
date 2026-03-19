#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(const pair<double, int>& a, const pair<double, int>& b){
    if (a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    sort(stages.begin(), stages.end());
    int sz = stages.size();
    vector<pair<double, int>> v;
    int prev = stages[0];
    int cnt = 0;
    
    for (int i = 0; i < N; i++){
        v.push_back({0, i + 1});
    }
    for (int i = 0; i < stages.size(); i++){
        if (prev != stages[i]) {
            v[prev - 1] = {(double)cnt / sz, prev};
            sz -= cnt;
            cnt = 1;
            prev = stages[i];
            continue ;
        } 
        cnt++;
    }
    if (prev != N + 1){
        v[prev - 1] = {cnt / sz, prev};
    }
    
    sort(v.begin(),v.end(),compare);
    for (int i = 0; i < N; i++){
        answer.push_back(v[i].second);
    }
    return answer;
}