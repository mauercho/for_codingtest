#include <bits/stdc++.h>



using namespace std;

int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};
int n, m;
const int max_n = 104;
int visited[max_n][max_n];
int arr[max_n][max_n];
int ni, nj;
int bfs(int n,int m){
	queue<pair<int, int>> q;
	int i, j;
	i = 0;
	j = 0;
	visited[i][j] = 1;
	q.push({i, j});
	while (q.size() > 0){
		tie(i, j) = q.front();
		q.pop();
		for (int k = 0; k < 4; k++){
			ni = i + di[k];
			nj = j + dj[k];
			if (!(0 <= ni && ni < n && 0 <= nj && nj < m))
                continue;
			if (visited[ni][nj] == 0 && arr[ni][nj] == 1){
				q.push({ni, nj});
				visited[ni][nj] = visited[i][j] + 1;
				if (ni == n - 1 && nj == m - 1){
					return (visited[ni][nj]);
				}
			}
		}
	}
	return -1;
}


int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			scanf("%1d", &arr[i][j]);
		}
	}
	cout << bfs(n,m);
}
