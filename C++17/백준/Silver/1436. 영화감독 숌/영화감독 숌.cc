#include <bits/stdc++.h>

using namespace std;

int t; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	int cnt = 0;
	for (int i = 666; i < 10000000; i++) {
		if (to_string(i).find("666") != string::npos) {
			cnt += 1;
		}
		if (cnt == t) {
			cout << i;
			break;
		}
	}
}