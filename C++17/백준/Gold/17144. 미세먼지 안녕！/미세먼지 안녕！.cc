#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int t, n, m;
int filter1 = -1, filter2 = -1;
int arr[51][51];
int copy_arr[51][51];
int goal;
int cnt = 0;
const int di[] = {1, -1, 0, 0};
const int dj[] = {0, 0, 1, -1};
vector<pair<int, int>> vec;
void air(){ // copy_arr에 값들 넣어주면 됨. 그리고 그 중간 빼주면 됨.

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			vec.clear();
			if (arr[i][j] > 0){
				for (int k = 0; k < 4; k++){
					int ni = i + di[k];
					int nj = j + dj[k];
					if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
					if (arr[ni][nj] == -1) continue;
					vec.push_back({ni, nj});
				}
				for (auto mem : vec){
					copy_arr[mem.first][mem.second] += arr[i][j] / 5;
				}
				copy_arr[i][j] -= (arr[i][j] / 5) * (int)vec.size();
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (copy_arr[i][j] == 0) continue;
			arr[i][j] += copy_arr[i][j];
		}
	}

}

void circulate(){
	int one_i = filter1, one_j = 0;
	int two_i = filter2, two_j = 0;
	pair<int, int> direc = {-1, 0};
	while (true){
		if (one_i == 0 && one_j == 0) direc = {0, 1};
		else if (one_i == 0 && one_j == m - 1) direc = {1, 0};
		else if (one_i == filter1 && one_j == m - 1) direc = {0, -1}; // 여기서 회전 해주고
		int ni = one_i + direc.first;
		int nj = one_j + direc.second;
		arr[one_i][one_j] = arr[ni][nj];
		one_i = ni, one_j = nj;
		if (one_i == filter1 && one_j == 0) break;
	}
	arr[filter1][1] = 0;
	direc = {1, 0};
	while (true){
		if (two_i == n - 1 && two_j == 0) direc = {0, 1};
		else if (two_i == n - 1 && two_j == m - 1) direc = {-1, 0};
		else if (two_i == filter2 && two_j == m - 1) direc = {0, -1}; // 여기서 회전 해주고
		int ni = two_i + direc.first;
		int nj = two_j + direc.second;
		arr[two_i][two_j] = arr[ni][nj];
		two_i = ni, two_j = nj;
		if (two_i == filter2 && two_j == 0) break;
	}
	arr[filter2][1] = 0;
	arr[filter1][0] = -1;
	arr[filter2][0] = -1;
}

int main(){
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> arr[i][j];
			if (arr[i][j] == -1){
				if (filter1 == -1) filter1 = i;
				else filter2 = i;
			}
		}
	}
	while (goal != t){
		fill(&copy_arr[0][0], &copy_arr[0][0] + 51 * 51, 0);
		air();//여기서 미세먼지 한바퀴 돌고 더해주고
		circulate(); // 여기서 공기 순환 한번
		goal++;
		// cout << goal << " " << t;
		// cout << "\n";
	}
	int sum = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (arr[i][j] > 0){
				sum += arr[i][j];
			}
		}
	}
	cout << sum;
	return 0;
}
