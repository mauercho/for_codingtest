#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;

using namespace std;
ll n, l, a, b;
vector<pair<ll, ll>> vec;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> l;

	ll gap = 0;
	ll end = 0;
	ll ans = 0;
	for (ll i = 0; i < n; i++){
		cin >> a >> b;
		vec.push_back({a, b});
	}
	sort(vec.begin(), vec.end());
	for (auto mem : vec){
		gap = (mem.second - mem.first);
		if (mem.second <= end) continue;
		else if (mem.first < end){
			gap = gap - (end - mem.first);
			if (gap % l){
				ans += (gap / l) + 1;
				end = end + ((gap / l) + 1) * l;
			}
			else {
				ans += gap / l;
				end += (gap / l) * l;
			}
		}
		else { // 관련없어.
			if (gap % l){
				ans += (gap / l) + 1;
				end = mem.first + ((gap / l) + 1) * l;
			}
			else {
				ans += (gap / l);
				end = mem.first +(gap / l) * l;
			}
		}
	}
	cout << ans;
	return 0;
}
