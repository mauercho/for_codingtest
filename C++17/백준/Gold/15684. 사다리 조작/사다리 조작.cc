#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int n, m, h, ret = INF;
int visited[31][11];
int a, b;

int check(){
	int start;
	for (int j = 1; j <= n; j++){
		start = j;
		for (int i = 1; i <= h; i++){
			if (visited[i][start - 1]) start--;
			else if (visited[i][start]) start++;
		}
		if (start != j) return 0;
	}
	return 1;
}

void go(int here, int cnt){
	if (cnt > 3 || ret <= cnt) return ;
	if (check()) {
		ret = cnt;
		return ;
	}
	for (int i = here; i <= h; i++){
		for (int j = 1; j < n; j++){
			if (visited[i][j - 1] || visited[i][j + 1] || visited[i][j]) continue;
			visited[i][j] = 1;
			go(i, cnt + 1);
			visited[i][j] = 0;
		}
	}
}

int main(){
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++){
		cin >> a >> b;
		visited[a][b] = 1;
	}
	go(1 ,0);
	cout << ((ret == INF) ? -1 : ret);
	return 0;
}