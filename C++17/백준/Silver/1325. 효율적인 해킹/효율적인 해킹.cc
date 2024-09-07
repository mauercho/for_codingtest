#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> adj[10001];
vector<int> tmp;
vector<int> copy_vec;
vector<int> ans;
vector<bool> visited;

void dfs(int a) {
    visited[a] = true;
    for (int mem : adj[a]) {
        if (!visited[mem]) {
            dfs(mem);
        }
    }
    tmp.push_back(a);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tmp1, tmp2;

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> tmp1 >> tmp2;
        adj[tmp2].push_back(tmp1);
    }

    for (int i = 1; i <= N; i++) {
        tmp.clear();
        visited.assign(N + 1, false);
        dfs(i);
        if (copy_vec.size() < tmp.size()) {
            copy_vec = tmp;
            ans.clear();
            ans.push_back(i);
        }
        else if (copy_vec.size() == tmp.size()) {
            ans.push_back(i);
        }
    }

    sort(ans.begin(), ans.end());
    for (int mem : ans) {
        cout << mem << " ";
    }
    return 0;
}