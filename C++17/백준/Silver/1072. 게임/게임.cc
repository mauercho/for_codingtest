#include <iostream>
#include <climits>

using namespace std;

typedef long long ll;
ll x, y;

bool check(ll middle, ll z){
	ll t_x = x + middle;
	ll t_y = y + middle;

	if (z != (t_y * 100) / t_x) return true;
	return false;
}

int main() {
	cin >> x >> y;
	ll z = (y * 100 / x) ;
	ll r = INT_MAX;
	ll l = 0;
	ll ret = LLONG_MAX;
	while (l <= r){
		ll middle = (r + l) / 2;
		if (check(middle, z)){
			r = middle - 1;
			ret = middle;
		} else {
			l = middle + 1;
		}
	}
	if (ret == LLONG_MAX) cout << -1;
	else cout << ret;

	return 0;
}
