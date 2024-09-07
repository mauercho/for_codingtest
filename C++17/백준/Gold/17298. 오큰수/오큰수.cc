#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> arr;
vector<int> ans;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tmp;
    int first, second;
    stack<pair<int, int>> stk;
    cin >> N;
    ans.assign(N, -1);
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    for (int i = 0; i < N; i++)
    {
        if (stk.empty())
        {
            stk.push({ i, arr[i] }); // 첫번째가 인덱스 두번째가 밸류
        }
        else
        { 
            if (stk.top().second < arr[i])
            {
                while (stk.size() > 0 && stk.top().second < arr[i])
                {
                    tie(first, second) = stk.top();
                    stk.pop();
                    ans[first] = arr[i];
                }
                stk.push({ i, arr[i] });
            }
            else
            {
                stk.push({ i, arr[i] });
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}