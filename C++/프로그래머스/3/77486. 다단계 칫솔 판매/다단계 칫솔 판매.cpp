#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size(), 0);
    unordered_map<string, string> parent_info;
    unordered_map<string, int> pos_info;
    
    for (int i = 0; i < enroll.size(); i++){
        parent_info[enroll[i]] = referral[i];
        pos_info[enroll[i]] = i;
    }
    for (int i = 0; i < seller.size(); i++){
        int price = amount[i] * 100;
        string person = seller[i];
        
        while (person[0] != '-'){
            int keep = price * 0.1;
            
            answer[pos_info[person]] += price - keep;
            if (keep < 1) break;
            price = keep;
            person = parent_info[person];
        }
    }
    return answer;
}