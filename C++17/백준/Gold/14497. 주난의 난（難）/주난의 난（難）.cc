#include <iostream>
#include <queue>
using namespace std;

int n, m;
int s_i, s_j, l_i, l_j;
string s;
struct A{
	int a, b, cnt;
};
vector<pair<int, int>> vec; // 여기다 넣을거임.
char arr[301][301];
const int di[] = {1, 0 , -1, 0};
const int dj[] = {0, 1, 0, -1};
int t_i, t_j;
int ni, nj;
int visited[301][301];
int cnt;
int flag;

void find_one(int i, int j){
	visited[i][j] = 1;

	for (int k = 0; k < 4; k++){
		ni = i + di[k];
		nj = j + dj[k];
		if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
		if (visited[ni][nj] == 1) continue;
		if (arr[ni][nj] == '0') find_one(ni, nj);
		else if (arr[ni][nj] == '1') vec.push_back({ni, nj});
		else flag = 1;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> s_i >> s_j >> l_i >> l_j;
	for (int i = 0; i < n; i++){
		cin >> s;
		for (int j = 0; j < m; j++){
			arr[i][j] = s[j]; // char로 받았음.
		}
	}
	s_i -= 1, s_j -= 1, l_i -= 1, l_j -= 1;
	// 초반에 s_i 주변에 0 담아야해.
	arr[s_i][s_j] = '0';
	cnt = 1;
	while (true){
		vec.clear();
		fill(&visited[0][0], &visited[0][0] + 301 * 301, 0);
		find_one(s_i, s_j);
		if (flag == 1) break ;
		for (auto mem : vec){
			arr[mem.first][mem.second] = '0';
		}
		cnt += 1;
	}

	cout << cnt;
}
