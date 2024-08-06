#include <bits/stdc++.h>

char alpha[26];

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 26; i++){
		alpha[i] = 'a' + i;
	}
	map<char, int> mp;
	string s;
	cin >> s;
	for (auto alpha : s) {
		if (mp[alpha]){
			mp[alpha] += 1;
		}
		else
			mp[alpha] = 1;
	}
	for (int i = 0; i < 26; i++){
		cout << mp[alpha[i]] << " ";
	}
}
