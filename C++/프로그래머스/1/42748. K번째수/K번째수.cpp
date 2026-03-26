#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (auto command: commands){
        vector<int> ref(array.begin() + command[0] - 1, array.begin() + command[1]);
        sort(ref.begin(), ref.end());
        answer.push_back(ref[command[2] - 1]);
    }
    return answer;
}