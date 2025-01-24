#include <iostream>
#include <queue>
using namespace std;

int n, m;
int visited[51][51];
int arr[51][51];
int first_ans, second_ans = 1, third_ans;
int width[2501];
pair<int, int> direc[4] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
int main(){
	cin >> m >> n;
	fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++){ // 한번 해야할께. visited 가 0 이면 체크해서 바꾸기.
		for (int j = 0; j < m; j++){
			if (!visited[i][j]){
				first_ans++;
				queue<pair<int, int>> q;
				int w = 1;
				visited[i][j] = first_ans;
				q.push({i, j});
				while (q.size()){
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++){
						if ((arr[y][x] & (1 << k)) == 0){
							int ni = y + direc[k].first;
							int nj = x + direc[k].second;
							if (ni < 0 || ni >= n || nj < 0 || nj >= m || visited[ni][nj] != 0) continue;
							visited[ni][nj] = first_ans;
							w++;
							q.push({ni, nj});
						}
					}
				}
				second_ans = max(second_ans, w);
				width[first_ans] = w;
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			for (int k = 0; k < 4; k++){
				if ((arr[i][j] & (1 << k)) != 0){
					int ni = i + direc[k].first;
					int nj = j + direc[k].second;
					if (ni < 0 || ni >= n || nj < 0 || nj >= m || visited[ni][nj] == visited[i][j]) continue;
					third_ans = max(third_ans, width[visited[i][j]] + width[visited[ni][nj]]);
				}
			}
		}
	}
	cout << first_ans << "\n" << second_ans << "\n" << third_ans;
	return 0;
}
