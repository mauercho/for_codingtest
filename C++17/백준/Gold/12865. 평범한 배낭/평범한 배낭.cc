#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int V, W;
int main(){
	cin >> N >> K;
	vector<int> dp(K + 1, 0);
	for (int i = 0; i < N; i++){
		cin >> W >> V;
		for (int j = K; j >= W; j--){
			dp[j] = max(dp[j], V + dp[j - W]);
		}
	}
	cout << dp[K];
	return 0;
}
