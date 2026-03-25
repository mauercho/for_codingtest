#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> st(nums.begin(), nums.end());
    
    answer = min(st.size(), nums.size()/2);
    return answer;
}