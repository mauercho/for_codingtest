#include <iostream>
#include <map>
#include <string>

using namespace std;

int R, C;
map<char, int> mp;
string s;
char arr[21][21];
int visited[21][21];
int max_val = 1;
int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};

void dfs(int a, int b, int cnt){
	max_val = max(max_val, cnt);
	for (int k = 0; k < 4; k++){
		int ni = a + di[k];
		int nj = b + dj[k];
		if (ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
		if (visited[ni][nj] || mp[arr[ni][nj]]) continue;
		visited[ni][nj] = 1;
		mp[arr[ni][nj]] = 1;
		dfs(ni, nj, cnt + 1);
		mp[arr[ni][nj]] = 0;
		visited[ni][nj] = 0;
	}
}

int main(){
	cin >> R >> C;
	fill(&visited[0][0], &visited[0][0] + 21 * 21, 0);
	for (int i = 0; i < R; i++){
		cin >> s;
		for (int j = 0; j < C; j++) arr[i][j]= s[j];
	}
	mp[arr[0][0]] = 1;
	visited[0][0] = 1;
	dfs(0, 0, 1);

	cout << max_val;
}
