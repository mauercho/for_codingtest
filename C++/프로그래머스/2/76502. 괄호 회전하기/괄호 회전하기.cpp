#include <string>
#include <vector>

using namespace std;

bool isVPS(string temp_s){
    vector<char> check;
    for (int i = 0; i < temp_s.size(); i++){
        char a = temp_s[i];
        if (a == ')' || a == '}' || a == ']'){
            if (check.empty()) return false;
            if (a == ')'){
                if (check[check.size() - 1] == '(') {
                    check.pop_back();
                } else return false;
            } else if (a == '}'){
                if (check[check.size() - 1] == '{') {
                    check.pop_back();
                } else return false;
            } else {
                if (check[check.size() - 1] == '[') {
                    check.pop_back();
                } else return false;
            }
        } else {
            check.push_back(a);
        }
    }
    if (!check.empty()){
        return false;
    }
    return true;
}

int solution(string s) {
    int answer = 0;
    int len = s.size();
    s += s;
    for (int i = 0; i < len; i++){
        if (isVPS(s.substr(i, len))){
            answer += 1;
        } 
    }
    return answer;
}