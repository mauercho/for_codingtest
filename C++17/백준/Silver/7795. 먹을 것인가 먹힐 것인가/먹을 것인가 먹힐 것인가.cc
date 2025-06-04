#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int n, m;

int main(){
	cin >> T;
	for (int i = 0; i < T; i++){
		vector<int> a;
		vector<int> b;
		cin >> n >> m;
		int temp;
		for (int i = 0; i < n; i++){
			cin >> temp;
			a.push_back(temp);
		}
		for (int i = 0; i < m; i++){
			cin >> temp;
			b.push_back(temp);
		}
		sort(b.begin(), b.end());
		int cnt = 0;
		for (int i = 0; i < n; i++){
			auto it = lower_bound(b.begin(), b.end(), a[i]);
			cnt += (it - b.begin());
		}
		cout << cnt << "\n";
	}
	return 0;
}
