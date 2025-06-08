#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
ll n, m;
ll l = 1;
ll r = 60000000004;
vector<int> v;
ll ret;
bool check(ll mid){
	ll cnt = m;
	for (auto mem : v){
		cnt += mid / mem;
	}
	if (cnt >= n) return true;
	return false;
}

int main(){
	cin >> n >> m;
	ll temp;
	if (n <= m) {cout << n; return 0;}
	for (int i = 0; i < m; i++){
		cin >> temp;
		v.push_back(temp);
	}
	while (l <= r){
		ll mid = (l + r) / 2;
		if (check(mid)){
			r = mid - 1;
			ret = mid;
		} else {
			l = mid + 1;
		}
	}
	ll time = m;
	for (auto mem: v){
		time += (ret - 1) / mem;
	}
	for (int i = 0; i < m; i++){
		if (ret % v[i] == 0) time++;
		if (time == n){
			cout << (i + 1);
			break;
		}
	}
	return 0;
}
