#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = ""; 
    map<string, int> s;
    for (auto mem: completion){
        s[mem] += 1;
    }
    for (auto mem: participant){
        if (s[mem] == 0){
            answer = mem;
            break;
        }
        s[mem] -= 1;
    }
    return answer;
}