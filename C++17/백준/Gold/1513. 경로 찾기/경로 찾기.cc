#include <iostream>
#include <cstring>

using namespace std;

int n, m, c;
int a, b;
int dp[51][51][51][51];
int arr[51][51];
const int MOD = 1000007;

int process(int i, int j, int cnt, int prev){
	if (i > n || j > m) return 0;
	if (cnt < 0) return 0;
	if (i == n && j == m){
		if (arr[i][j] == 0 && cnt == 0) return 1;
		if (arr[i][j] > prev && cnt == 1) return 1;
		return 0;
	}
	int &ret = dp[i][j][cnt][prev];
	if (ret != -1) return ret;
	ret = 0;
	if (arr[i][j] == 0){ // 여기에 가게 없음.
		ret = process(i + 1, j, cnt, prev) + process(i, j + 1, cnt, prev);
	}
	else if (arr[i][j] > prev){
		ret = process(i + 1, j, cnt - 1, arr[i][j]) + process(i, j + 1, cnt - 1, arr[i][j]);
	}
	return ret % MOD;
}

int main(){
	cin >> n >> m >> c;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= c; i++){
		cin >> a >> b;
		arr[a][b] = i;
	}
	for (int i = 0; i <= c; i++){
		cout << process(1, 1, i, 0) << " ";
	}
	return 0;
}
