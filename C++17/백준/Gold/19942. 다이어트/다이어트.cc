#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;
int n;
int mp, mf, ms, mv;
int p[16], f[16], s[16], v[16], c[16];
int temp_cost, t_p, t_f, t_s, t_v;
const int INF = 987654321;
int ans = INF;
vector<int> vec;
vector<int> ans_vec;
int main(){
	cin >> n;
	int ref = (int)pow(2, n);
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < n; i++){
		cin >> p[i] >> f[i] >> s[i] >> v[i] >> c[i];
	}
	for (int num = 1; num < ref; num++){
		temp_cost = t_p = t_f = t_s = t_v = 0;
		vec.clear();
		for (int pos = 0; pos < n; pos++){
			if (num & (1 << pos)){
				vec.push_back(pos + 1);
				temp_cost += c[pos];
				t_p += p[pos];
				t_f += f[pos];
				t_s += s[pos];
				t_v += v[pos];
			}
			if (temp_cost > ans) break;
		}
		if (t_p >= mp && t_f >= mf && t_s >= ms && t_v >= mv){
			if (temp_cost < ans){
				ans = temp_cost;
				ans_vec = vec;
			}
			else if (temp_cost == ans){
				if (ans_vec > vec){
					ans_vec = vec;
				}
			}
		}
	}
	if (ans == INF) cout << -1;
	else {
		cout <<ans << "\n";
		for (int i = 0; i < ans_vec.size(); i++) cout << ans_vec[i] << " ";
	}
	return 0;
}
