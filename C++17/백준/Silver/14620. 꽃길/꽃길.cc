#include <iostream>
#include <vector>

using namespace std;
int n;
int ret = 987654321;
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};
int v[11][11];
int arr[11][11];

int check(int a, int b){
	for (int k = 0; k < 4; k++){
		int ni = a + di[k];
		int nj = b + dj[k];
		if (ni < 0 || ni >= n || nj < 0 || nj >= n || v[ni][nj]) return 0;
	}
	return 1;
}

int changereturn(int a, int b){
	int val = 0;
	v[a][b] = 1;
	val += arr[a][b];
	for (int k = 0; k < 4; k++){
		int ni = a + di[k];
		int nj = b + dj[k];
		v[ni][nj] = 1;
		val += arr[ni][nj];
	}
	return val;
}

void erase(int a, int b){
	v[a][b] = 0;
	for (int k = 0; k < 4; k++){
		int ni = a + di[k];
		int nj = b + dj[k];
		v[ni][nj] = 0;
	}
}
void dfs(int cnt, int hap){
	if (ret < hap) return ;
	if (cnt == 3){
		ret = min(ret, hap);
		return ;
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (check(i, j)){ // check에서 i, j 되나 확인
				dfs(cnt + 1, hap + changereturn(i, j));
				erase(i, j);
			}
		}
	}
}
int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	dfs(0, 0);
	cout << ret;
}
