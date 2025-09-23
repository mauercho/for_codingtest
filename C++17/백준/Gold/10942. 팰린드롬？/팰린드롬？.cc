#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector<int> v;
int tmp;
int S, E;
int dp[2001][2001]; // a 에서 b까지가 펠린드롬임 ?

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	v.push_back(0);
	for (int i = 0; i < N; i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 1; i <= N; i++){
		dp[i][i] = 1; // 하나하나는 펠린드롬임.
	}
	for (int i = 1; i < N; i++){
		if (v[i] == v[i + 1]) dp[i][i + 1] = 1;
	}
	for (int size = 2; size < N; size++){
		for (int i = 1; i + size <= N ; i++){
			if (v[i] == v[i + size] && dp[i + 1][i + size - 1]) dp[i][i + size] = 1;
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++){
		cin >> S >> E;
		cout << dp[S][E] << "\n";
	}

	return 0;
}
