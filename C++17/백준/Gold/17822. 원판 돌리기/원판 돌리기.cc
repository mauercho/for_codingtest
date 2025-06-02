#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m, t;
int x, d, k;

void change(vector<int> &index, vector<vector<int>> &temp) {
    set<pair<int, int>> change_set;
    int sum = 0, cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][(j + index[i]) % m] == 1001) continue;
            int cur = temp[i][(j + index[i]) % m];

            int nj = (j + 1) % m;
            int right = temp[i][(nj + index[i]) % m];
            if (right != 1001 && cur == right) {
                change_set.insert({i, (j + index[i]) % m});
                change_set.insert({i, (nj + index[i]) % m});
            }

            if (i + 1 < n) {
                int down = temp[i + 1][(j + index[i + 1]) % m];
                if (down != 1001 && cur == down) {
                    change_set.insert({i, (j + index[i]) % m});
                    change_set.insert({i + 1, (j + index[i + 1]) % m});
                }
            }

            sum += cur;
            cnt++;
        }
    }

    if (change_set.empty()) {
        if (cnt == 0) return;
        double avg = (double)sum / cnt;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int &val = temp[i][(j + index[i]) % m];
                if (val == 1001) continue;
                if (val > avg) val--;
                else if (val < avg) val++;
            }
        }
    } else {
        for (auto mem : change_set) {
            temp[mem.first][mem.second] = 1001;
        }
    }
}

void do_thing(int x, int d, int k, vector<vector<int>> &temp, vector<int> &index) {
    for (int i = x; i <= n; i += x) {
        if (d == 1) { // 반시계
            index[i - 1] = (index[i - 1] + k) % m;
        } else if (d == 0) { // 시계
            index[i - 1] = (index[i - 1] + (m - k % m)) % m;
        }
    }
    change(index, temp);
}

int main() {
    cin >> n >> m >> t;
    vector<vector<int>> v(n, vector<int>(m, 0));
    vector<int> index(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < t; i++) {
        cin >> x >> d >> k;
        do_thing(x, d, k, v, index);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] != 1001) sum += v[i][j];
        }
    }
    cout << sum;
    return 0;
}
