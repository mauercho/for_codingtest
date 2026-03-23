#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int idx1 = 0, idx2 = 0, final_idx = 0;
    string temp;
    for (int i = 0; i < goal.size(); i++){
        temp = goal[final_idx];
        if (idx1 < cards1.size() && temp == cards1[idx1]){
            final_idx++;
            idx1++;
        } else if (idx2 < cards2.size() && temp == cards2[idx2]){
            final_idx++;
            idx2++;
        } else {
            break;
        }
    }
    if (final_idx == goal.size()) answer = "Yes";
    else answer = "No";
    return answer;
}