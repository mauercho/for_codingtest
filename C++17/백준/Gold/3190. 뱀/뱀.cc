#include <iostream>
#include <deque>

using namespace std;
int n, k, a, b, l, x;
char C;
int board[101][101];
int visited[101][101];
pair<int, int> direc[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main(){
	cin >> n >> k;
	deque<pair<int, char>> info;
	for (int i = 0; i < k; i++){
		cin >> a >> b;
		board[a - 1][b - 1] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++){
		cin >> x >> C;
		info.push_back({x, C});
	}
	deque<pair<int, int>> dq;

	dq.push_back({0, 0});
	int direc_pos = 0;
	int time = 0;
	int ni, nj;
	int i, j, tempI, tempJ;
	visited[0][0] = 1;
	while (true){
		time++;
		i = dq.front().first, j = dq.front().second;
		ni = i + direc[direc_pos].first;
		nj = j + direc[direc_pos].second;
		if (ni < 0 || ni >= n || nj < 0 || nj >= n || visited[ni][nj]) break;
		dq.push_front({ni, nj});
		visited[ni][nj] = 1;
		if (board[ni][nj] == 1){ // 사과
			board[ni][nj] = 0;
		}
		else{
			tempI = dq.back().first;
			tempJ = dq.back().second;
			visited[tempI][tempJ] = 0;
			dq.pop_back();
		}
		if (time == info.front().first){
			if (info.front().second == 'D'){
				direc_pos = (direc_pos + 1) % 4;
			}
			else {
				direc_pos = (direc_pos + 3) % 4;
			}

			info.pop_front();
		}
	}
	cout << time;
	return 0;
}
