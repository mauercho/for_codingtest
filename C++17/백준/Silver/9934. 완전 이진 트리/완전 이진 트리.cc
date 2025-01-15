#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;
int level;
int node;
vector<int> vec[11];
int arr[1025];
int visited[1025];
void dfs(int depth, int mid){
	visited[mid] = 1;
	vec[depth].push_back(arr[mid]);
	if (depth < level){
		int temp = (int)pow(2, level - (depth + 1));
		if (mid - temp >= 0 && !visited[mid - temp]){
			dfs(depth + 1, mid - temp);
		}
		if (mid + temp < node && !visited[mid + temp]){
			dfs(depth + 1, mid + temp);
		}
	}
}

int main(){
	cin >> level;
	node = (int)pow(2, level) - 1;
	memset(visited, 0, sizeof(visited));
	for (int i = 0 ; i < node; i++) cin >> arr[i];
	dfs(1, node / 2);
	for (int i = 1; i <= level; i++){
		for (auto mem: vec[i]) cout << mem << " ";
		cout << "\n";
	}
	return 0;
}
