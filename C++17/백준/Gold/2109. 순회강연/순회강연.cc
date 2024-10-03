#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n;
vector<pair<int, int>> plans;
int temp_p, temp_d;
int ret;
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int k = 0; k < n; k++){
		cin >> temp_p >> temp_d;
		plans.push_back({temp_d, temp_p});
	}
	sort(plans.begin(), plans.end());
	for (int i = 0; i < n; i++){
		pq.push(plans[i].second);
		while (pq.size() > plans[i].first){
			pq.pop();
		}
	}
	while (pq.size()){
		ret += pq.top();
		pq.pop();
	}
	cout << ret;
}
