#include <bits/stdc++.h>

using namespace std;
int t;
int a;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t; 
	int ret1, ret2;
	for (int i = 0; i < t; i++) {
		ret1 = 0;
		ret2 = 0;
		cin >> a;
		for (int j = 2; j <= a; j *= 2) {
			ret1 += (a / j);
		}
		for (int j = 5; j <= a; j *= 5) {
			ret2 += (a / j);
		}
		cout << min(ret1, ret2) << "\n";
	}
}