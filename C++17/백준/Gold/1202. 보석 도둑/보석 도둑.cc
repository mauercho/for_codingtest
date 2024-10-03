#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
int n, k;
vector<pair<ll, ll>> jewels;
vector<ll> bags;
ll ret;
int main(){
	ll temp1, temp2, temp3;
	cin >> n >> k;
	priority_queue<ll> q;
	for (int i = 0; i < n; i++){
		cin >> temp1 >> temp2;
		jewels.push_back({temp1, temp2});
	}
	for (int i = 0; i < k; i++){
		cin >> temp3;
		bags.push_back(temp3);
	}
	sort(jewels.begin(), jewels.end());
	sort(bags.begin(), bags.end());
	int j = 0;
	for (int i = 0; i < k; i++){
		while (j < n && jewels[j].first <= bags[i]) q.push(jewels[j++].second);
		if (q.size()){
			ret += q.top();
			q.pop();
		}
	}
	cout << ret << "\n";
	return 0;
}
