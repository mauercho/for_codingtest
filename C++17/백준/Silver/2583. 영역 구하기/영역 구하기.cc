#include <bits/stdc++.h>
using namespace std;

int m, n, num, arr[101][101], visited[101][101];
int x, y;
int x_1, x_2, y_1, y_2;
int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};

vector<int> width;
void fill_arr(int x_1, int y_1, int x_2, int y_2){
	int b1 = max(x_1, x_2);
	int a1 = max(y_1, y_2);
	int b2 = min(x_1, x_2);
	int a2 = min(y_1, y_2);

	for (int i = a2; i < a1; i++){
		for (int j = b2; j < b1; j++){
			arr[i][j] = 1;
		}
	}
}

int get_width(int y, int x){
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	int width = 1;
	int i;
	int j;
	int ni, nj;
	q.push({y, x});
	while (q.size()){
		tie(i, j) = q.front();
		q.pop();
		for (int k =0; k < 4; k++){
			ni = i + di[k];
			nj = j + dj[k];
			if (!(0 <= ni && ni < n && 0 <= nj && nj < m)){
				continue;
			}
			if (visited[ni][nj] == 0 && arr[ni][nj] == 0){
				visited[ni][nj] = 1;
				q.push({ni, nj});
				width += 1;
			}
		}
	}
	return width;
}

int main(){
	cin >> n >> m >> num;
	int cnt = 0;
	for (int i = 0; i < num; i++){
		cin >> x_1 >> y_1>> x_2>> y_2;
		fill_arr(x_1, y_1, x_2, y_2);
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (visited[i][j] == 0 && arr[i][j] == 0){
				cnt += 1;
				width.push_back(get_width(i, j));
			}
		}
	}
	sort(width.begin(), width.end());
	cout << cnt << "\n";
	for (auto mem : width){
		cout << mem << " ";
	}
}
