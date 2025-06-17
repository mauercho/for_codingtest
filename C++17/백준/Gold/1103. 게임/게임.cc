#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int N, M;
vector<string> board;
int dp[51][51];
bool visited[51][51];

const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};

int dfs(int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= M) return 0;
    if (board[i][j] == 'H') return 0;

    if (visited[i][j]) {
        cout << -1 << endl;
        exit(0);
    }

    int& ret = dp[i][j];
    if (ret != -1) return ret;

    visited[i][j] = true;
    ret = 0;

    int num = board[i][j] - '0';

    for (int k = 0; k < 4; k++) {
        int ni = i + num * di[k];
        int nj = j + num * dj[k];
        ret = max(ret, dfs(ni, nj) + 1);
    }

    visited[i][j] = false;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    string row_str;
    for (int i = 0; i < N; i++) {
        cin >> row_str;
        board.push_back(row_str);
    }

    memset(dp, -1, sizeof(dp));

    cout << dfs(0, 0) << endl;

    return 0;
}
