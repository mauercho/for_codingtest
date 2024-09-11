#include <bits/stdc++.h>
using namespace std;

int N;
int damage[6][3] = { {9, 3, 1}, {9, 1, 3}, {3, 1, 9}, {3, 9, 1}, {1, 3, 9}, {1, 9, 3} };
int arr[3];
int visited[61][61][61];
int a, b, c;
int na, nb, nc;
int do_func() {
    queue<tuple<int, int, int>> q;
    q.push({ arr[0], arr[1], arr[2] });
    visited[arr[0]][arr[1]][arr[2]] = 1;
    while (q.size()) {
        tie(a, b, c) = q.front();
        q.pop();
        for (int i = 0; i < 6; i++) {
            na = max(0, a - damage[i][0]);
            nb = max(0, b - damage[i][1]);
            nc = max(0, c - damage[i][2]);
            if (visited[na][nb][nc] > 0 || visited[na][nb][nc] > visited[a][b][c] + 1) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({ na, nb, nc });
        }
    }
    return (visited[0][0][0] - 1);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << do_func();
    return 0;
}