#include <bits/stdc++.h>
using namespace std;

int R, C;
char arr[1001][1001];
int fire_check[1001][1001];
int visited_check[1001][1001];
vector<pair<int, int>> fire;
int start_i, start_j;
int flag;

const int di[] = { 1, 0, -1, 0 };
const int dj[] = { 0, 1, 0, -1 };

void do_fire_check(vector<pair<int, int>> fires) {
    queue<pair<int, int>> q;
    int ni, nj, i, j;
    for (pair<int, int> fire : fires) {
        q.push({ fire.first, fire.second });
        fire_check[fire.first][fire.second] = 0;
    }
    while (q.size()) {
        tie(i, j) = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            ni = i + di[k];
            nj = j + dj[k];
            if (ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
            if (fire_check[ni][nj] >= 0) continue;
            if (arr[ni][nj] == '#') continue;
            fire_check[ni][nj] = fire_check[i][j] + 1;
            q.push({ ni, nj });
        }
    }
}

void bfs(int start_i, int start_j) {
    queue<pair<int, int>> q;
    int ni, nj, i, j;
    q.push({ start_i, start_j });
    visited_check[start_i][start_j] = 0;
    while (q.size()) {
        tie(i, j) = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            ni = i + di[k];
            nj = j + dj[k];
            if (ni < 0 || ni >= R || nj < 0 || nj >= C) {
                flag = visited_check[i][j] + 1;
                return;
            }
            if (arr[ni][nj] == '#') continue;
            if (visited_check[ni][nj] >= 0) continue;
            if (fire_check[ni][nj] != -1 && fire_check[ni][nj] <= visited_check[i][j] + 1) continue;
            visited_check[ni][nj] = visited_check[i][j] + 1;
            q.push({ ni, nj });
        }
    }
}

int main() {
    cin >> R >> C;
    flag = -1;
    fill(&fire_check[0][0], &fire_check[0][0] + 1001 * 1001, -1);
    fill(&visited_check[0][0], &visited_check[0][0] + 1001 * 1001, -1);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'F') {
                fire.push_back({ i, j });
            }
            else if (arr[i][j] == 'J') {
                start_i = i;
                start_j = j;
            }
        }
    }
    do_fire_check(fire);
    bfs(start_i, start_j);
    if (flag == -1)
    {
        cout << "IMPOSSIBLE";
    }
    else {
        cout << flag;
    }
    return 0;
}