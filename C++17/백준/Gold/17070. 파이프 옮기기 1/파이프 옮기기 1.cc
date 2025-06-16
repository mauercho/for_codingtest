#include <iostream>
#include <cstring>
using namespace std;
int arr[20][20];
int n;
int dp[20][20][3];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	memset(dp, 0, sizeof(dp));
	dp[0][1][2] = 1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i == 0 && j == 0) continue;
			if (arr[i][j + 1] != 1){
				dp[i][j + 1][2] += dp[i][j][1];
				dp[i][j + 1][2] += dp[i][j][2];
			}
			if (arr[i + 1][j + 1] == 0 && arr[i + 1][j] == 0 && arr[i][j + 1] == 0){
				dp[i + 1][j + 1][1] += dp[i][j][0];
				dp[i + 1][j + 1][1] += dp[i][j][1];
				dp[i + 1][j + 1][1] += dp[i][j][2];
			}
			if (arr[i + 1][j] != 1){
				dp[i + 1][j][0] += dp[i][j][0];
				dp[i + 1][j][0] += dp[i][j][1];
			}
		}
	}


	cout << dp[n-1][n-1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
	return 0;
}
