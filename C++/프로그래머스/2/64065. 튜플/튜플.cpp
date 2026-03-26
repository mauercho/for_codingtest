#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool cmp(string &a, string &b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    string tmp(s.begin() + 1, s.end() - 1);
    auto pos = tmp.find("},{");
    vector<string> v;
    unordered_set<int> st;
    int start_pos = 0;
    while (pos != string::npos){
        v.push_back(tmp.substr(start_pos, pos + 1 - start_pos));
        start_pos = pos + 2;
        pos = tmp.find("},{", start_pos + 2);
    }
    v.push_back(tmp.substr(start_pos));
    sort(v.begin(), v.end(), cmp);
    for (auto mem: v){
        string tmp2(mem.begin() + 1, mem.end() - 1);
        vector<string> num_vec;
        start_pos = 0;
        pos = tmp2.find(",");
        while (pos != string::npos){
            num_vec.push_back(tmp2.substr(start_pos, pos - start_pos));
            start_pos = pos + 1;
            pos = tmp2.find(",", start_pos);
        }
        num_vec.push_back(tmp2.substr(start_pos));
        for (auto z: num_vec){
            if (st.count(stoi(z)) == 0){
                st.insert(stoi(z));
                answer.push_back(stoi(z));
            } 
        }
    }
    return answer;
}