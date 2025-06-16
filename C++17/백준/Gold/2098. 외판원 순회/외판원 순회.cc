#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int n;
int dp[20][1<<20];
int dist[20][20];
const int INF = 987654321;
int process(int here, int visited){
	if (visited == (1 << n) - 1){
		if (dist[here][0] == 0) { // 갈 수없음.
			return INF;
		}
		else {
			return dist[here][0];
		}
	}
	int &ret = dp[here][visited];

	if (ret != -1) return ret;
	ret = INF;

	for (int i = 0; i < n; i++){
		if (visited & (1 << i)) continue; // 간적있음.
		if (dist[here][i] == 0) continue;
		ret = min(ret, process(i, visited | (1 << i)) + dist[here][i]);
	}
	return ret;
}

int main(){
	cin >> n;
	int tmp;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> tmp;
			dist[i][j] = tmp;
		}
	}
	int ans = process(0, 1);
	cout << ans;
	return 0;
}
