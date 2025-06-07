#include <iostream>
#include <climits>
#include <vector>
using namespace std;
int s,c;
typedef long long ll;
ll sum_val = 0;
vector<ll> v;
ll r, l, temp, ans;

bool check(ll mid){
	int cnt = 0;
	for (ll mem: v){
		cnt += mem / mid;
	}
	if (cnt >= c) return true;
	else return false;
}

int main(){
	cin >> s >> c;
	for (int i = 0; i < s; i++){
		cin >> temp;
		v.push_back(temp);
		r += temp;
	}
	l = 1;
	ll sum_val;
	sum_val = r;
	while (l <= r){
		ll mid = (l + r) / 2;
		if (check(mid)){
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << sum_val - (ans * c);
	return 0;
}
