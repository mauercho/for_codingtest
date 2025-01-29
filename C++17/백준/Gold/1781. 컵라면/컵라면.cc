#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
int n, t_d, t_p;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> t_d >> t_p;
		v.push_back({t_d, t_p});
	}
	sort(v.begin(), v.end());
	int day;
	for (int i = 0; i < n; i++){
		day = v[i].first;
		pq.push(v[i].second);
		while (pq.size() > day){
			pq.pop();
		}
	}
	int sum = 0;
	while (!pq.empty()){
		sum += pq.top(); pq.pop();
	}
	cout << sum;
	return 0;
}
