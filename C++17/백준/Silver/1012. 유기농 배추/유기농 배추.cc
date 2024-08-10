#include <bits/stdc++.h>

using namespace std;

const int max_n = 51;
int num;
int n, m, k;
int a, b;
int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};
int ni, nj;
void do_bfs(int i, int j, int arr[max_n][max_n], int visited[max_n][max_n]){
	queue<pair<int, int>> q;

	visited[i][j] = 1;
	q.push({i, j});
	while (q.size() > 0){
		tie(i, j) = q.front();
		q.pop();
		for (int t = 0; t < 4; t++){
			ni = i + di[t];
			nj = j + dj[t];
			if (!(0 <= ni && ni < n && 0 <= nj && nj < m))
                continue;
			if (visited[ni][nj] == 0 && arr[ni][nj] == 1){
				q.push({ni, nj});
				visited[ni][nj] = 1;
			}
		}
	}
}

int main(){
	cin >> num;
	for (int z = 0; z < num; z++){
		int cnt = 0;
		int visited[max_n][max_n] = {0,};
		int arr[max_n][max_n] = {0,};
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++){
			cin >> a >> b;
			arr[b][a] = 1;
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (visited[i][j] == 0 && arr[i][j] == 1){
					do_bfs(i, j, arr, visited);
					cnt += 1;
				}
			}
		}
		cout << cnt << "\n";
	}
}
