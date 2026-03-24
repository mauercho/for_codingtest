#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool sum_mp(unordered_map<string, int> tmp_mp){
    for (auto mem: tmp_mp){
        if (mem.second != 0) return false; 
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> mp;
    
    for (int i = 0; i < number.size(); i++){
        mp[want[i]] = number[i];
    }// 다 넣어줬음.
    for (int i = 0; i < 10; i++){
        if (mp.count(discount[i])){
            mp[discount[i]] -= 1;
        }
    }
    if (sum_mp(mp)){
        answer += 1;
    }
    for (int i = 0; i < discount.size() - 10; i++){
        if (mp.count(discount[i])){
            mp[discount[i]] += 1;
        } 
        if (mp.count(discount[i + 10])){
            mp[discount[i + 10]] -= 1;
        }
        if (sum_mp(mp)){
            answer += 1;
        }
    }
    return answer;
}