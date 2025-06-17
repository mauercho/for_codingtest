#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[1001][32][2]; // 시간? 몇번 움직임? 위치?
int T, W;
int main(){
	cin >> T >> W;
	int tmp;
	int ans = 0;
	memset(dp, -1, sizeof(dp)); // -1 로 초기화함.
	dp[0][0][0] = 0; // 0초에 0 번 움직임.

	for (int i = 1; i <= T; i++){ // 시간
		cin >> tmp;
		for (int j = 0; j <= W; j++){ // 몇번 움직임.
			if (dp[i - 1][j][0] != -1){ // 있으면
				if (tmp == 1){
					dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0] + 1);
					dp[i][j + 1][1] = max(dp[i][j + 1][1], dp[i - 1][j][0]);
				}
				else { // tmp == 2 일때
					dp[i][j + 1][1] = max(dp[i][j + 1][1], dp[i - 1][j][0] + 1);
					dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0]);
				}
			}
			if (dp[i - 1][j][1] != -1){ // 2 나무에 있음.
				if (tmp == 1){
					dp[i][j + 1][0] = max(dp[i][j + 1][0], dp[i - 1][j][1] + 1);
					dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][1]);
				}
				else {
					dp[i][j + 1][0] = max(dp[i][j + 1][0], dp[i - 1][j][1]);
					dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][1] + 1);
				}
			}
		}
	}
	for(int j=0; j<=W; ++j) {
        ans = max({ans, dp[T][j][0], dp[T][j][1]});
    }
	cout << ans;
	return 0;
}
