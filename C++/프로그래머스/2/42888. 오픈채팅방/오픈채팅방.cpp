#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> mp;
    vector<pair<string, string>> course;
    for (auto mem: record){
        if (mem[0] == 'E'){
            int pos = mem.find(' ', 6);     
            mp[mem.substr(6 , pos - 6)] = mem.substr(pos + 1);
            course.push_back({"Enter", mem.substr(6 ,pos - 6)});
        } else if (mem[0] == 'L'){
            course.push_back({"Leave", mem.substr(6)});
        } else {
            int pos = mem.find(' ', 7);   
            mp[mem.substr(7, pos - 7)] = mem.substr(pos + 1);
        }
    }
    for (auto mem: course){
        string words = "";
        words += mp[mem.second];
        if (mem.first == "Enter"){
            words += "님이 들어왔습니다.";
        } else {
            words += "님이 나갔습니다.";
        }
        answer.push_back(words);
    }
    return answer;
}