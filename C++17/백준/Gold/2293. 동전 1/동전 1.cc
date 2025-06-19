#include <iostream>
#include <algorithm>
using namespace std;

int n, k, temp;
typedef long long ll;
ll dp[10004];
int main(){
	cin >> n >> k;
	fill(dp, dp + 10001, 0);
	dp[0] = 0;
	for (int i = 0; i < n; i++){
		cin >> temp;
		if (temp > 10000) continue;
		dp[temp]++;
		for (int j = temp + 1; j <= k; j++){
			if (dp[j - temp] != 0){
				dp[j] += dp[j - temp];
			}
		}
	}
	cout << dp[k];
	return 0;
}
