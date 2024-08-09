#include <bits/stdc++.h>

using namespace std;

int input_num;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> input_num) {
		int ret = 1; 
		ll cnt = 1;
		while (true) {
			if (cnt % input_num == 0) {	
				break;
			}
			ret += 1;
			cnt = cnt * 10 + 1;
            cnt %= input_num;
		}
		cout << ret << "\n";
	}
}