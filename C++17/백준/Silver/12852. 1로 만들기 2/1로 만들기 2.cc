#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1000001];
int N;

int main(){
	cin >> N;
	fill(&dp[0], &dp[0] + 1000001, 987654321);
	dp[1] = 0;
	for (int i = 2; i <= N; i++) {
		if (i % 3 == 0){
			dp[i] = min(dp[i / 3] + 1, dp[i]);
		}
		if (i % 2 == 0){
			dp[i] = min(dp[i / 2] + 1, dp[i]);
		}
		dp[i] = min(dp[i], dp[i - 1] + 1);
	}
	vector<int> vec;
	int ref = dp[N];
	cout << ref;
	cout << "\n";
	int next = N;
	cout << next << " ";
	while (next != 1){
		if (next % 2 == 0 && dp[next / 2] == ref - 1){
			next = next / 2;
			cout << next << " ";
			ref--;
		}
		else if (next % 3 == 0 && dp[next / 3] == ref - 1){
			next = next / 3;
			cout << next << " ";
			ref--;
		}
		else {
			next = next - 1;
			cout << next << " ";
			ref--;
		}
	}
	return 0;
}
