#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};
int _min = 1e9;
int n, m;
int arr[10][10];
int cnt;
vector<vector<vector<int>>> directions = {
	{},
	{{0}, {1}, {2}, {3}}, // 1 번
	{{0, 2}, {1, 3}}, // 2 번
	{{0, 1}, {1, 2}, {2, 3}, {3, 0}}, // 3 번
	{{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}}, // 4 번
	{{0, 1, 2, 3}}, // 5 번
};
vector<pair<int, int>> cctv;

vector<pair<int, int>> extend_cctv(vector<int>& set, int i, int j){
	vector<pair<int, int>> v;

	for (auto &mem: set){
		int ni = i + di[mem];
		int nj = j + dj[mem];
		while (0 <= ni && ni < n && 0 <= nj && nj < m && arr[ni][nj] != 6){
			if (arr[ni][nj] == 0){
				arr[ni][nj] = 8;
				v.push_back({ni, nj});
			}
			ni += di[mem];
			nj += dj[mem];
		}
	}
	return v;
}

void dfs(int here){
	if (here == cnt){
		int sum = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (arr[i][j] == 0){
					sum += 1;
				}
			}
		}
		_min = min(_min, sum);
		return ;
	}
	int i = cctv[here].first;
	int j = cctv[here].second;
	int type = arr[i][j];
	for (auto &mem: directions[type]){
		vector<pair<int, int>> _change = extend_cctv(mem, i, j);
		dfs(here + 1);
		for (auto &mem : _change){
			arr[mem.first][mem.second] = 0;
		}
	}

}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> arr[i][j];
			if (arr[i][j] != 0 && arr[i][j] != 6){
				cnt += 1; // cctv 개수
				cctv.push_back({i, j});
			}
		}
	}
	dfs(0);
	cout << _min;
	return 0;
}