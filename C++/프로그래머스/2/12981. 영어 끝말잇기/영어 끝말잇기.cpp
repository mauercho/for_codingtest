#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> mp;
    answer = {0, 0};
    char last_word;
    for (int i = 0; i < words.size(); i++){
        if (mp.count(words[i])) {
            answer = {(i % n) + 1, i / n + 1};
            break;
        }
        if (i == 0){
            last_word = words[0][words[0].size() - 1];   
        } else {
            if (last_word != words[i][0]) {
                answer = {(i % n) + 1, i / n + 1};
                break;
            }
            last_word = words[i][words[i].size() - 1]; 
        }
        mp[words[i]] = 1;
    }

    return answer;
}