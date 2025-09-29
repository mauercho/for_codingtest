#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string s;
int dp[2504][2504];
int n;
int dp2[2504];
const int INF = 987654321;

int go(int here){
	if (here == s.size()) return 0;
	if (dp2[here] != INF) return dp2[here];
	int &ret = dp2[here];
	for (int i = 1; i + here <= s.size(); i++){
		if (dp[here][i]) ret = min(ret, go(here + i) + 1);
	}
	return ret;
}

int main(){
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++){
		dp[i][1] = 1; // 길이 1 짜리
	}
	for (int i = 0; i < n - 1; i++){
		if (s[i] == s[i + 1]) dp[i][2] = 1;
	}
	for (int size = 3; size <= n; size++){
		for (int i = 0; i + size <= n; i++){
			if (s[i] == s[i + size - 1] && dp[i + 1][size - 2]) dp[i][size] = 1;
		}
	}
	// 여기까지 dp 구했음.
	fill(dp2, dp2 + 2504, INF);
	cout << go(0);
	return 0;
}
