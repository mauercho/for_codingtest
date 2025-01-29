#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> v;
int n, a, b;
int lastTime;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a >> b;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++){
		if (lastTime < v[i].first) lastTime = v[i].first + v[i].second;
		else lastTime = lastTime + v[i].second;
	}
	cout << lastTime;
	return 0;
}
