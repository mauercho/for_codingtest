#include <iostream>
#include <string>

using namespace std;
int R, C, K;
char arr[10][10];
int v[10][10];
int cnt;
string s;
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};

void dfs(int a, int b, int c){
	if (c > K) return ;
	if (a == 0 && b == C - 1){
		if (c == K)
			cnt += 1;
		return ;
	}
	for (int k = 0; k < 4; k++) {
		int ni = a + di[k];
		int nj = b + dj[k];
		if (ni < 0 || ni >= R || nj < 0 || nj >= C || v[ni][nj]) continue;
		if (arr[ni][nj] == 'T') continue;
		v[ni][nj] = 1;
		dfs(ni, nj, c + 1);
		v[ni][nj] = 0;
	}
}

int main(){
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++){
		cin >> s;
		for (int j = 0; j < C; j++) arr[i][j] = s[j];
	}
	v[R - 1][0] = 1;
	dfs(R - 1, 0, 1);
	cout << cnt;
}
