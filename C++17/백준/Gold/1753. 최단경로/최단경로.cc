#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 987654321;
int v, e;
int start;
int u, end_point, w;


int main(){
	cin >> v >> e;
	cin >> start;
	vector<int> distance(v + 1, INF);
	vector<vector<pair<int,int>>> adj(v + 1);
	for (int i = 0; i < e; i++){
		cin >> u >> end_point >> w;
		adj[u].push_back({w, end_point});
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	distance[start] = 0;
	pq.push({0, start});
	while (pq.size()){
		auto [dist, node] = pq.top();
		pq.pop();
		if (distance[node] < dist) continue;
		for (auto next_node: adj[node]){
			int cost = next_node.first + dist;
			if (distance[next_node.second] > cost){
				distance[next_node.second] = cost;
				pq.push({cost, next_node.second});
			}
		}
	}
	for (int i = 1; i <= v; i++){
		if (distance[i] == INF) cout << "INF" << "\n";
		else cout << distance[i] << "\n";
	}
	return 0;
}
