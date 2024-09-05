#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int arr[8][8];
int max_area = 0;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };

void spread_virus(int copy_arr[8][8]) {
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (copy_arr[i][j] == 2) {
                q.push({ i, j });
            }
        }
    }

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int t = 0; t < 4; t++) {
            int ni = i + di[t];
            int nj = j + dj[t];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m && copy_arr[ni][nj] == 0) {
                copy_arr[ni][nj] = 2;
                q.push({ ni, nj });
            }
        }
    }
}

int count_safe_area(int copy_arr[8][8]) {
    int safe_area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (copy_arr[i][j] == 0) {
                safe_area++;
            }
        }
    }
    return safe_area;
}

void dfs(int count) {
    if (count == 3) {
        int copy_arr[8][8];
        copy(&arr[0][0], &arr[0][0] + 64, &copy_arr[0][0]);
        spread_virus(copy_arr);
        max_area = max(max_area, count_safe_area(copy_arr));
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                arr[i][j] = 1;
                dfs(count + 1);
                arr[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    dfs(0);
    cout << max_area;
    return 0;
}