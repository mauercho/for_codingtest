#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int x, y;
int ret;
vector<pair<int, int>> v;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x >> y;
		v.push_back({x, y});
	}
	sort(v.begin(), v.end());
	int start = v[0].first;
	int end = v[0].second;
	for (int i = 1; i < n; i++){
		if (end >= v[i].first && v[i].second >= end){
			end = v[i].second;
		}
		else if (end < v[i].first){
			ret += (end - start);
			start = v[i].first;
			end = v[i].second;
		}
	}
	ret += (end - start);
	cout << ret;
	return 0;
}
