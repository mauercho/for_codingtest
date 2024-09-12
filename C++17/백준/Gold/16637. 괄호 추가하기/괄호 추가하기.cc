#include <bits/stdc++.h>

using namespace std;

int N;
int mx = INT_MIN;
string s;

int operation(char oper, int a, int b){
	if (oper == '+') return a + b;
	else if (oper == '-') return a - b;
	else return a * b;
}

void dfs(int num, int idx){
	if (idx >= N - 1){
		mx = max(mx, num);
		return ;
	}
	int num2 = operation(s[idx + 1], num, s[idx + 2] - '0');
	dfs(num2, idx + 2);
	if (idx + 4 < N){
		int num3 = operation(s[idx + 3], s[idx + 2] - '0', s[idx + 4] - '0');
		dfs(operation(s[idx + 1], num, num3), idx + 4);
	}
}

int main()
{
	cin >> N >> s;
	dfs(s[0] - '0', 0);
	cout << mx;
}
