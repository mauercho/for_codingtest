#include <iostream>
#include <map>
using namespace std;

map<int, int> _map;
int n, m;
int main(){
	cin >> n >> m;
	int temp;
	for (int i = 0; i < n; i++){
		cin >> temp;
		_map[temp]++;
	}
	for (int i = 0; i < m; i++){
		cin >> temp;
		_map[temp]++;
	}
	int cnt = 0;
	for (auto mem: _map){
		if (mem.second == 1) cnt++;
	}
	cout << cnt;
	return 0;
}
