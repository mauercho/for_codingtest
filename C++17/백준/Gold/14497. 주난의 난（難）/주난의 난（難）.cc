// #include <iostream>
// #include <queue>
// using namespace std;

// int n, m;
// int s_i, s_j, l_i, l_j;
// string s;
// struct A{
// 	int a, b, cnt;
// };
// vector<pair<int, int>> vec; // 여기다 넣을거임.
// char arr[301][301];
// const int di[] = {1, 0 , -1, 0};
// const int dj[] = {0, 1, 0, -1};
// int t_i, t_j;
// int ni, nj;
// int visited[301][301];
// int cnt;
// int flag;

// void find_one(int i, int j){
// 	visited[i][j] = 1;

// 	for (int k = 0; k < 4; k++){
// 		ni = i + di[k];
// 		nj = j + dj[k];
// 		if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
// 		if (visited[ni][nj] == 1) continue;
// 		if (arr[ni][nj] == '0') find_one(ni, nj);
// 		else if (arr[ni][nj] == '1') vec.push_back({ni, nj});
// 		else flag = 1;
// 	}
// }

// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
// 	cin >> n >> m >> s_i >> s_j >> l_i >> l_j;
// 	for (int i = 0; i < n; i++){
// 		cin >> s;
// 		for (int j = 0; j < m; j++){
// 			arr[i][j] = s[j]; // char로 받았음.
// 		}
// 	}
// 	s_i -= 1, s_j -= 1, l_i -= 1, l_j -= 1;
// 	// 초반에 s_i 주변에 0 담아야해.
// 	arr[s_i][s_j] = '0';
// 	cnt = 1;
// 	while (true){
// 		vec.clear();
// 		fill(&visited[0][0], &visited[0][0] + 301 * 301, 0);
// 		find_one(s_i, s_j);
// 		if (flag == 1) break ;
// 		for (auto mem : vec){
// 			arr[mem.first][mem.second] = '0';
// 		}
// 		cnt += 1;
// 	}

// 	cout << cnt;
// }


// #include <stdio.h>
// #include<algorithm>
// #include<queue>
// using namespace std;
// char a[301][301];
// int n, m, x1, y1, x2, y2;
// typedef pair<int, int> pii;
// int visited[301][301];
// const int dy[4] = {-1, 0, 1, 0};
// const int dx[4] = {0, 1, 0, -1};
// int ret;
// queue<int> q;
// int main(){
//     scanf("%d %d", &n, &m);
//     scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
//     y1--, x1--, y2--, x2--;
//     for(int i = 0; i < n; i++){
//         scanf("%s", a[i]);
//     }
//     q.push(1000 * y1 + x1);
//     visited[y1][x1] = 1;
//     int cnt = 0;
//     while(a[y2][x2] != '0'){
//         cnt++;
//         queue<int> temp;
//         while(q.size()){
//             int y = q.front() / 1000;
//             int x = q.front() % 1000;
//             q.pop();
//             for(int i = 0; i < 4; i++){
//                 int ny = y + dy[i];
//                 int nx = x + dx[i];
//                 if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
//                 visited[ny][nx] = cnt;
//                 if(a[ny][nx] != '0'){
//                     a[ny][nx] = '0';
//                     temp.push(1000 * ny + nx);
//                 }
//                 else q.push(1000 * ny + nx);
//             }
//         }
//         q = temp;
//     }
//     printf("%d\n", visited[y2][x2]);
// }

// RE

#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
int n, m;
queue<int> q;
int i1, j1, i2, j2;
int cnt;
char arr[304][304];
int visited[304][304];
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};
int a, b;
int temp;
int main(){
	cin >> n >> m;
	cin >> i1 >> j1 >> i2 >> j2;
	i1 -=1, j1 -=1, i2 -=1, j2 -= 1;
	cin.ignore();
	for (int i = 0; i < n; i++){
		scanf("%s", arr[i]);
	}
	q.push(1000 * i1 + j1);
	visited[i1][j1] = 1;
	while (visited[i2][j2] == 0){
		queue<int> tmp;
		cnt++;
		while (q.size()){
			temp = q.front(); q.pop();
			a = temp / 1000;
			b = temp % 1000;
			for (int k = 0; k < 4; k++){
				int ni = a + di[k];
				int nj = b + dj[k];
				if (ni < 0 || ni >= n || nj < 0 || nj >= m || visited[ni][nj]) continue;
				if (arr[ni][nj] == '1'){
					tmp.push(1000 * ni + nj);
					visited[ni][nj] = cnt;
					arr[ni][nj] = '0';
				}
				else { // 0이나 #
					q.push(1000 * ni + nj);
					visited[ni][nj] = cnt;
				}
			}
		}
		q = tmp;
	}
	cout << visited[i2][j2];
}
