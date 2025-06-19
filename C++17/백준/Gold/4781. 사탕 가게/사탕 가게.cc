#include <iostream>
#include <climits>
#include <cmath>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n, c, p_int, p_double;
int dp[10001]; // 특정 가격대에 있는 최고 칼로리
int m_int, m_double;
int main(){
	while (true){
		scanf("%d", &n);
		scanf("%d.%d", &m_int, &m_double);
		fill(dp, dp + 10001, -1);
		int p = 100 * m_int + m_double;
		if (n == 0) break;
		int ans = 0;
		dp[0] = 0;
		for (int i = 0; i < n; i++){
			scanf("%d", &c);
			scanf("%d.%d", &p_int, &p_double);
			int tmp = 100 * p_int + p_double;
			if (dp[tmp] == -1) dp[tmp] = c;
			for (int j = tmp; j <= p; j++){
				if (dp[j - tmp] != -1){ // 있음.
					dp[j] = max(dp[j], dp[j - tmp] + c);
					ans = max(ans, dp[j]);
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
