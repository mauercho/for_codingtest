#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<pair<int, int>> vec;
int from, to;
int main(){
	cin >> n;
	for (int k = 0; k < n; k++){
		cin >> from >> to;
		vec.push_back({to, from});
	}
	int start = -1;
	int cnt = 0;
	sort(vec.begin(), vec.end());
	for (auto a: vec){
		if (start <= a.second){
			cnt += 1;
			start = a.first;
		}
	}
	cout << cnt;
}
