#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
// #include <iostream>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if (a.second != b.second)
        return a.second > b.second;  
    return a.first < b.first;        
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<int, string>> v;
    map<string, int> mp;
    map<string, vector<pair<int, int>>> check_mp;
    for (int i = 0; i < plays.size(); i++){
        mp[genres[i]] += plays[i];
        check_mp[genres[i]].push_back({i, plays[i]});
    }
    for (auto mem: mp){
        v.push_back({mem.second, mem.first});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++){
        auto [a, b] = v[v.size() - 1 - i]; // a는 크기 b는 genre
        if (check_mp[b].size() == 1) {
            answer.push_back(check_mp[b][0].first);
        } else {
            sort(check_mp[b].begin(), check_mp[b].end(), cmp);
            answer.push_back(check_mp[b][0].first);
            answer.push_back(check_mp[b][1].first);
        }
    }
    return answer;
}