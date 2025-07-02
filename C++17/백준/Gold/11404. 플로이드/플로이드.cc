#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int dist[104][104];
const int INF = 987654321;
int main(){
	cin >> n >> m;
	int a, b, c;

	fill(&dist[0][0], &dist[0][0] + 104 * 104, INF);

	for (int i = 0; i < m; i++){
		cin >> a >> b >> c;
		dist[a - 1][b - 1] =min(dist[a - 1][b - 1], c);
	}
	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i == j || dist[i][j] >= INF) cout << "0" << " ";
			else{
				cout << dist[i][j] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
