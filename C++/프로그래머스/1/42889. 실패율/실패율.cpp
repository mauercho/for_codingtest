#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<double, int> a, pair<double, int> b){
    if (a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> tmp; 
    sort(stages.begin(), stages.end());
    int cnt = stages.size();
    for (int i = 1; i <= N; i++){
        int nu = count(stages.begin(), stages.end(), i);
        if (cnt != 0){
            tmp.push_back({(double)nu / cnt, i});
        }
        else tmp.push_back({0, i});
        cnt -= nu;
    }
    sort(tmp.begin(), tmp.end(), compare);
    
    for (auto ddd: tmp){
        answer.push_back(ddd.second);
    }
    return answer;
}