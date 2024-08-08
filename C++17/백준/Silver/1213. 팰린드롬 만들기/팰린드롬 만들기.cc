#include <bits/stdc++.h>

using namespace std;

string s;
string input_str;
int can_pallen;
map<char, int> mp;
string ans;
char odd;
string reverse_str;
int main() {
	cin >> input_str;
	for (auto alpha : input_str) {
		if (mp[alpha]) {
			mp[alpha] += 1;
		}
		else
			mp[alpha] = 1;
	}
	for (auto sec : mp) {
		if (sec.second % 2 == 1)
		{
			can_pallen += 1;
			odd = sec.first;
			for (int i = 0; i < sec.second / 2; i++) {
				ans += sec.first;
			}
		}
		else {
			for (int i = 0; i < sec.second / 2; i++) {
				ans += sec.first;
			}
		}
		if (can_pallen >= 2) {
			cout << "I'm Sorry Hansoo";
			exit(0);
		}		
	}
	sort(ans.begin(), ans.end());
	reverse_str = ans;
	reverse(reverse_str.begin(), reverse_str.end());

	if (can_pallen == 1) {
		ans += odd;
	}
	ans += reverse_str;
	cout << ans;
}