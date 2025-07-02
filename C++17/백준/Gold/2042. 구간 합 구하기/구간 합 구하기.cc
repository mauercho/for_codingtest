#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
int n, m, k;

ll sum(vector<ll> &tree, int idx){
	ll ans = 0;
	while (idx > 0){
		ans += tree[idx];
		idx -= (idx & -idx);
	}
	return ans;
}

void update(vector<ll> &tree, int idx, ll diff){
	while (idx < tree.size()){
		tree[idx] += diff;
		idx += (idx & -idx);
	}
}

int main(){

	cin >> n >> m >> k;
	vector<ll> tree(n + 1, 0);
	vector<ll> vec(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> vec[i];
		update(tree, i, vec[i]);
	}
	ll a, c;
	int b;
	for (int i = 0; i < m + k; i++){
		cin >> a >> b >> c;
		if (a == 1){
			ll diff = c - vec[b];
			vec[b] = c;
			update(tree, b, diff);
		}
		else {
			cout << sum(tree, c) - sum(tree, b - 1) << "\n";
		}
	}
	return 0;
}
