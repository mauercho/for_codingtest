#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;

bool compare(pair<int, int> a, pair<int, int> b){
	if (a.first > b.first){
		return false;
	}
	return true;
}
vector<pair<int, int>> v;
int a, b;
int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a >> b;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end(), compare);
	// for (auto mem : v){
	// 	cout << mem.first << " " << mem.second << "\n";
	// }
	vector<int> lis;
	for (auto mem: v){
		auto it = lower_bound(lis.begin(), lis.end(), mem.second);
		if (it == lis.end()){
			lis.push_back(mem.second);
		} else{
			*it = mem.second;
		}
	}
	cout << n - lis.size();
	return 0;
}
