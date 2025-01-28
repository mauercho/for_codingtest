#include <stack>
#include <iostream>
#include <string>

using namespace std;
int n, ret;
string s;
stack<int> stk;
int dp[200001];
int main(){
	cin >> n >> s;
	for (int i = 0; i < n; i++){
		if (s[i] == '('){
			stk.push(i);
		}
		else { // ) 들어온건데
			if (stk.size() > 0) {
				dp[stk.top()] = dp[i] = 1;
				stk.pop();
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++){
		if (dp[i]){
			cnt++;
			ret = max(cnt, ret);
		}
		else {
			cnt = 0;
		}
	}
	cout << ret;
	return 0;
}
