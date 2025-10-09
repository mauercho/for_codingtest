#include <iostream>

using namespace std;
typedef long long ll;


ll arr[102], dp[102][21], n;

ll go(ll idx ,ll sum){
	if (sum > 20 || sum < 0) return 0;

	ll &ret = dp[idx][sum];
	if (ret) return ret;
	if (idx == n - 2){
		if (sum == arr[n - 1]) return 1;
		return 0;
	}
	ret += go(idx + 1, sum + arr[idx + 1]);
	ret += go(idx + 1, sum - arr[idx + 1]);
	return ret;
}


int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << go(0, arr[0]);
	return 0;
}
