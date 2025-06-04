#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int n, attack;
struct info{
	int t, a, h;
};

typedef long long ll;
ll r = LLONG_MAX;
ll l = 0;
vector<info> v;

bool check(ll middle){

	ll h_cur = middle;
	ll temp_attack = attack;
	for (auto mem: v){
		int temp_t = mem.t;
		int temp_a = mem.a;
		int temp_h = mem.h;
		if (temp_t == 1){
			ll cnt = temp_h / temp_attack;
			if (temp_h % temp_attack != 0){
				cnt++;
			}
			if (h_cur - ((cnt - 1) * temp_a) <= 0){
				return false;
			}
			h_cur -= (cnt - 1) * temp_a;
		} else {
			h_cur += temp_h;
			if (h_cur > middle) h_cur = middle;
			temp_attack += temp_a;
		}
	}
	return true;
}

int main(){

	cin >> n >> attack;
	int t, a, h;
	// int h_cur = h_max;
	ll ret;
	for (int i = 0; i < n; i++){
		cin >> t >> a >> h;
		v.push_back({t, a, h});
	}
	while (l <= r){
		ll middle = (l + r) / 2;
		if (check(middle)){
			ret = middle;
			r = middle - 1;
		} else {
			l = middle + 1;
		}
	}
	cout << ret;
	return 0;
}
