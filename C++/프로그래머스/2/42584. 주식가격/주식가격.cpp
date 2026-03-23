#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 10);
    vector<pair<int, int>> stk;
    for (int i = 0; i < prices.size(); i++){
        if (stk.empty()) stk.push_back({prices[i], i});
        else {
            int temp = prices[i];
            while (!stk.empty() && stk.back().first > temp){ // 스택이 차있고
                answer[stk.back().second] = i - stk.back().second; 
                stk.pop_back();
            }
            stk.push_back({prices[i], i});
        }
    }
    while (!stk.empty()){
        answer[stk.back().second] = prices.size() - 1 - stk.back().second;
        stk.pop_back();
    }
    return answer;
}