#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
int n, m, a, b, c;
const ll INF = 1e18;
ll dist[1004];

int main(){
    cin >> n >> m;
    vector<pair<int, int>> adj[1004];
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, c});
    }
    fill(&dist[0], &dist[0] + 1004, INF);
    dist[0] = 0;
    bool negative_cycle = false;
    for (int i = 0; i < n; i++){
        for (int here = 0; here < n; here++){
            for (auto mem: adj[here]){
                int d = mem.second;
                int to = mem.first;
                if (dist[here] != INF && dist[here] + d < dist[to]){
                    if (i == n - 1) negative_cycle = true;
                    dist[to] = dist[here] + d;
                }
            }
        }
    }
    if (negative_cycle) cout << -1;
    else {
        for (int i = 1; i < n; i++){
            if (dist[i] == INF) cout << -1 << "\n";
            else cout << dist[i] << "\n";
        }
    }
    return 0;
}
