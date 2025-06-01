#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[10][10];
vector<pair<int, int>> cctv;
int min_sum = 1e9;

int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};

vector<pair<int, int>> extend_cctv(int here, int direction){
	int i = cctv[here].first;
	int j = cctv[here].second;
	vector<pair<int, int>> temp;
	if (arr[i][j] == 1){
		int ni = i + di[direction];
		int nj = j + dj[direction];
		while (0 <= ni && ni < n && 0 <= nj && nj < m && arr[ni][nj] != 6){
			if (arr[ni][nj] == 0) {
				arr[ni][nj] = 8;
				temp.push_back({ni, nj});
			}
			ni = ni + di[direction];
			nj = nj + dj[direction];
		}
	}
	else if (arr[i][j] == 2){
		int ni = i + di[direction];
		int nj = j + dj[direction];
		while (0 <= ni && ni < n && 0 <= nj && nj < m && arr[ni][nj] != 6){
			if (arr[ni][nj] == 0) {
				arr[ni][nj] = 8;
				temp.push_back({ni, nj});
			}
			ni = ni + di[direction];
			nj = nj + dj[direction];
		}
		ni = i + di[(direction + 2) % 4];
		nj = j + dj[(direction + 2) % 4];
		while (0 <= ni && ni < n && 0 <= nj && nj < m && arr[ni][nj] != 6){
			if (arr[ni][nj] == 0) {
				arr[ni][nj] = 8;
				temp.push_back({ni, nj});
			}
			ni = ni + di[(direction + 2) % 4];
			nj = nj + dj[(direction + 2) % 4];
		}
	}
	else if (arr[i][j] == 3){
		int ni = i + di[direction];
		int nj = j + dj[direction];
		while (0 <= ni && ni < n && 0 <= nj && nj < m && arr[ni][nj] != 6){
			if (arr[ni][nj] == 0) {
				arr[ni][nj] = 8;
				temp.push_back({ni, nj});
			}
			ni = ni + di[direction];
			nj = nj + dj[direction];
		}
		ni = i + di[(direction + 1) % 4];
		nj = j + dj[(direction + 1) % 4];
		while (0 <= ni && ni < n && 0 <= nj && nj < m && arr[ni][nj] != 6){
			if (arr[ni][nj] == 0) {
				arr[ni][nj] = 8;
				temp.push_back({ni, nj});
			}
			ni = ni + di[(direction + 1) % 4];
			nj = nj + dj[(direction + 1) % 4];
		}
	}
	else if (arr[i][j] == 4){
		int ni = i + di[direction];
		int nj = j + dj[direction];
		while (0 <= ni && ni < n && 0 <= nj && nj < m && arr[ni][nj] != 6){
			if (arr[ni][nj] == 0) {
				arr[ni][nj] = 8;
				temp.push_back({ni, nj});
			}
			ni = ni + di[direction];
			nj = nj + dj[direction];
		}
		ni = i + di[(direction + 1) % 4];
		nj = j + dj[(direction + 1) % 4];
		while (0 <= ni && ni < n && 0 <= nj && nj < m && arr[ni][nj] != 6){
			if (arr[ni][nj] == 0) {
				arr[ni][nj] = 8;
				temp.push_back({ni, nj});
			}
			ni = ni + di[(direction + 1) % 4];
			nj = nj + dj[(direction + 1) % 4];
		}
		ni = i + di[(direction + 2) % 4];
		nj = j + dj[(direction + 2) % 4];
		while (0 <= ni && ni < n && 0 <= nj && nj < m && arr[ni][nj] != 6){
			if (arr[ni][nj] == 0) {
				arr[ni][nj] = 8;
				temp.push_back({ni, nj});
			}
			ni = ni + di[(direction + 2) % 4];
			nj = nj + dj[(direction + 2) % 4];
		}
	}
	else {
		for (int c = 0; c < 4; c++){
			int ni = i + di[c];
			int nj = j + dj[c];
			while (0 <= ni && ni < n && 0 <= nj && nj < m && arr[ni][nj] != 6){
				if (arr[ni][nj] == 0) {
                    arr[ni][nj] = 8;
                    temp.push_back({ni, nj});
                }
				ni = ni + di[c];
				nj = nj + dj[c];
			}
		}
	}
	return temp;
}

void dfs(int cnt){
	if (cnt == cctv.size()){
		int sum = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (arr[i][j] == 0) sum += 1;
			}
		}
		min_sum = min(min_sum, sum);
		return;
	}
	for (int i = 0; i < 4; i++){ // 4방향으로 돌림.
		vector<pair<int, int>> change = extend_cctv(cnt, i);
		dfs(cnt + 1);
		for (auto mem: change){
			arr[mem.first][mem.second] = 0;
		}
	}

}

int main(){
	cin >> n >> m;
	// int ans = n * m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> arr[i][j];
			if (arr[i][j] != 0){
				if (arr[i][j] != 6){
					cctv.push_back({i, j});
				}
				// ans -= 1;
			}
		}
	} // 0의 갯수를 세줌.
	dfs(0);
	cout << min_sum;
	return 0;
}
