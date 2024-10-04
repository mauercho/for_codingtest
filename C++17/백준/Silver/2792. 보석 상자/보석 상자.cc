#include <iostream>
#include <vector>
using namespace std;


typedef long long ll;
ll M, N;
vector<ll> v;
ll ans = 1e18;
ll temp;
ll s = 1;
ll e = 0;
ll mid;

bool check(ll num){
	ll cnt = 0;
	for (int i = 0; i < v.size(); i++){
		cnt += v[i] / num;
		if (v[i] % num){
			cnt += 1;
		}
	}
	return N >= cnt;
}

int main(){
	cin >> N >> M;
	for (int k = 0; k < M; k++){
		cin >> temp;
		e = max(temp, e);
		v.push_back(temp);
	}
	while (s <= e){
		mid = (s + e) / 2;
		if (check(mid)){
			ans = mid;
			e = mid - 1;
		}
		else
			s = mid + 1;
	}
	cout << ans;
}
