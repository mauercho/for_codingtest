#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
ll dp[31][32]; // 앞에가 1개짜리 약, 두번째가 반개 짜리 약


void process(){
	for (int i = 1; i < 31; i++){
		for (int j = 0; j < 31; j++){
			if (j == 0) dp[i][j] = dp[i - 1][1];
			else dp[i][j] = dp[i - 1][j + 1] + dp[i][j - 1];
		}
	}
}

int main(){
	int tmp;
	memset(dp, 0, sizeof(dp));
	dp[1][0] = 1; // WH 경우의 수 밖에 없음.
	for (int i = 1; i < 31; i++){
		dp[0][i] = 1;
	}
	process();
	while(true){
		cin >> tmp;
		if (tmp == 0)break;
		cout << dp[tmp][0] << "\n";
	}
	return 0;
}
