#include <iostream>
#include <vector>
using namespace std;
int n, arr[21][21];
int ans = 987654321;

void dfs(int depth, int cnt, int num){
	int sumStart = 0;
	int sumLink = 0;
	if (cnt > n / 2) return ;
	if (depth == n && cnt == n / 2){ // 1의 갯수
		//여기서 1 갯수 세어서 차 구해주기.
		vector<int> vec;
		vector<int> vec2;
		for (int k = 0; k < n; k++){
			if ((num & (1 << k))!= 0) {
				vec.push_back(k);
			}
			else {
				vec2.push_back(k);
			}
		}
		for (int a : vec){
			for (int b : vec){
				sumStart += arr[a][b];
			}
		}
		for (int a : vec2){
			for (int b: vec2){
				sumLink += arr[a][b];
			}
		}
		ans = min(ans, abs(sumLink - sumStart));
		return ;
	}
	else if (depth > n) return ;
	dfs(depth + 1, cnt, num);
	dfs(depth + 1, cnt + 1, num |= (1 << depth)); // 0부터 계산 해줄걸?
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	dfs(0, 0, 0);
	cout << ans;
	return 0;
}
