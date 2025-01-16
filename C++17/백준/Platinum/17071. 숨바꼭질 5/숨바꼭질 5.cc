#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int n, k, turn = 1;
const int max_n = 500000;
int visited[2][max_n + 4];
int ok;
int main(){
	cin >> n >> k;
	q.push(n);
	visited[0][n] = 1;
	if (n == k){ cout << 0; return 0; }
	while (true){
		k += turn;
		if (k > max_n) break;
		if (visited[turn % 2][k]){
			ok = 1;
			break;
		}
		int qSize = q.size();
		for (int i = 0; i < qSize; i++){
			int temp = q.front(); q.pop();
			for (int ni : {temp + 1, temp - 1, temp * 2}){
				if (ni < 0 || ni > max_n || visited[turn % 2][ni]) continue;
				visited[turn % 2][ni] = 1;
				q.push(ni);
				if (ni == k){
					ok = 1;
					break;
				}
			}
			if (ok) break;
		}
		if (ok) break;
		turn++;
	}
	if (ok) cout << turn;
	else cout << -1;
	return 0;
}
