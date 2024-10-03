#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
struct {
	int p, f, s, v, c;
} arr[16];
map<int, vector<vector<int>>> ret_v;
const int INF = 987654321;
int mp, mf, ms, mv;
int b, c, d, e, sum;
int ret = INF;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < N; i++){
		cin >> arr[i].p >> arr[i].f >> arr[i].s >> arr[i].v >> arr[i].c;
	}
	for (int i = 1; i < (1 << N); i++){
		b = c = d = e = sum = 0;
		vector<int> v;
		for (int j = 0; j < N; j++){
			if (i & (1 << j)){
				v.push_back(j + 1);
				b += arr[j].p;
				c += arr[j].f;
				d += arr[j].s;
				e += arr[j].v;
				sum += arr[j].c;
			}
		}
		if (b >= mp && c >= mf && d >= ms && e >= mv){
			if (ret >= sum){
				ret = sum;
				ret_v[ret].push_back(v);
			}
		}
	}
	if (ret == INF)
		cout << -1;
	else {
		cout << ret << "\n";
		sort(ret_v[ret].begin(), ret_v[ret].end());
		for (int a : ret_v[ret][0]){
			cout << a << " ";
		}
	}
	return 0;
}
