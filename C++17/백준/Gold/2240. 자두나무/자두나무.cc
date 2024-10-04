#include <iostream>
#include <cstring>
using namespace std;

int t, w;
int dp[1001][3][31];
int b[1001];

int go(int time, int tree, int n)
{
    if (n < 0) return -1e9;
    if (time == t) return 0;
    int &ret = dp[time][tree][n];
    if (ret != -1) return ret;
    ret = max(go(time + 1, tree, n), go(time + 1, 3 - tree, n - 1)) + (tree == b[time]);
    return ret;
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> t >> w;
    for (int i = 0; i < t; i++){
        cin >> b[i];
    }
    cout << max(go(0, 1, w), go(0, 2, w - 1));
    return 0;
}
