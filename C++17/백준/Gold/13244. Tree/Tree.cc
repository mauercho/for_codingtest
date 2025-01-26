#include <iostream>
#include <vector>

using namespace std;

int t, n, m; // t <= 10 n <= 1000;
vector<int> nodes[1001];
int a, b;
int visited[1001];
void dfs(int now){
	visited[now] = 1;
	for (auto next : nodes[now]){
		if (!visited[next])
			dfs(next);
	}
}

int main(){
	cin >> t;
	for (int tc = 0; tc < t; tc++){
		cin >> n >> m;
		for (int i = 1; i <= n; i++){
			nodes[i].clear();
		}
		fill(visited, visited + 1001, 0);
		for (int i = 0; i < m; i++){
			cin >> a >> b;
			nodes[a].push_back(b);
			nodes[b].push_back(a);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++){
			if (!visited[i]){
				dfs(i);
				cnt += 1;
			}
		}
		if ((m == n - 1) && (cnt == 1)) cout << "tree\n";
		else cout << "graph\n";
	}
	return 0;
}
