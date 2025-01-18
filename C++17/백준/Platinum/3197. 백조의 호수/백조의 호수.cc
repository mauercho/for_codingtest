#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <tuple>
using namespace std;

int cnt;
int R, C;
int visited_swan[1501][1501], visited_melting[1501][1501];
char arr[1501][1501];
string s;
queue<pair<int, int>> swanQ, waterQ, waterQ_temp, swanQ_temp;
int start_i, start_j;
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};

void QClear(queue<pair<int , int>> &q){
	queue<pair<int, int>> empty;
	swap(q, empty);
}

int move_swan(){
	int t_i, t_j;
	while (swanQ.size()){
		tie(t_i, t_j) = swanQ.front();
		swanQ.pop();
		for (int k = 0; k < 4; k++){
			int ni = t_i + di[k];
			int nj = t_j + dj[k];
			if (ni < 0 || ni >= R || nj < 0 || nj >= C || visited_swan[ni][nj]) continue;
			visited_swan[ni][nj] = 1;
			if (arr[ni][nj] == 'X')	swanQ_temp.push({ni, nj});
			else if (arr[ni][nj] == '.') swanQ.push({ni, nj});
			else return 1;
		}
	}
	return 0;
}

void melting(){
	int t_i, t_j;
	while (waterQ.size()){
		tie(t_i, t_j) = waterQ.front();
		waterQ.pop();
		for (int k = 0; k < 4; k++){
			int ni = t_i + di[k];
			int nj = t_j + dj[k];
			if (ni < 0 || ni >= R || nj < 0 || nj >= C || visited_melting[ni][nj]) continue;
			// 여기서 ni nj 는 X 갈수도 L 갈수도 . 갈수도 . 가면 스킵 해야함. 근데 위에서 스킵함.
			if (arr[ni][nj] == 'X'){
				arr[ni][nj] = '.';
				visited_melting[ni][nj] = 1;
				waterQ_temp.push({ni, nj});
			}
		}
	}
}

int main(){
	cin >> R >> C;
	for (int i = 0; i < R; i++){
		cin >> s;
		for (int j = 0; j < C; j++){
			arr[i][j] = s[j];
			if (arr[i][j] == 'L') {
				start_i = i;
				start_j = j;
			}
			if (arr[i][j] == 'L' || arr[i][j] == '.') {
				waterQ.push({i, j});
				visited_melting[i][j] = 1;
			}
		}
	}
	swanQ.push({start_i, start_j});
	visited_swan[start_i][start_j] = 1;
	while (true){
		if (move_swan()) break;
		melting();
		swanQ = swanQ_temp;
		waterQ = waterQ_temp;
		QClear(swanQ_temp);
		QClear(waterQ_temp);
		cnt++;
	}

	cout << cnt;
	return 0;
}
