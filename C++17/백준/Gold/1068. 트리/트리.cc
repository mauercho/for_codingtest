#include <iostream>
#include <vector>

using namespace std;
int n, root, r;
int input_num;
vector<int> graph[54];

int dfs(int start){
	int ret = 0;
	int child = 0;

	for (int next : graph[start]){
		if (next == r) continue;
		ret += dfs(next);
		child += 1;
	}
	if (child == 0) return 1;
	return ret;
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> input_num;
		if (input_num == -1) root = i;
		graph[input_num].push_back(i);
	}

	cin >> r;
	if (r == root){
		cout << 0;
		return 0;
	}
	cout << dfs(root);
	return 0;
}
