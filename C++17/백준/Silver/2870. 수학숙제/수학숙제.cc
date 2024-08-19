#include <bits/stdc++.h>

using namespace std;

int n;
string s;
vector<string> v;
string tmp = "";

bool cmp(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	return a.size() < b.size();
}

bool all_zero(string a) { // 모두 0인지 체크 모두 0이면 1 리턴
	for (char alpha : a) {
		if (alpha != '0') {
			return 0;
		}
	}
	return 1;
}

string changed(string a) {
	string s = "";
	int first_zero = 1;

	if (all_zero(a)) {
		s = "0";
	}
	else {
		if (a[0] == '0') {
			for (char alpha : a) {
				if (first_zero == 1 && alpha == '0') { // 처음 0 만
				}
				else {
					first_zero = 0;
					s += alpha;
				}
			}
		}
		else {
			for (char alpha : a) {
				s += alpha;
			}
		}
	}
	return s;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (char alpha : s) {
			if (alpha >= '0' && alpha <= '9') {
				tmp += alpha; 
			}
			else {
				if (tmp.size() != 0)
				{
					v.push_back(changed(tmp));
					tmp = "";
				}
			}
		}
		if (tmp.size() != 0) {
			v.push_back(changed(tmp));
		}
		tmp = "";
	}
	sort(v.begin(), v.end(), cmp);
	for (string mem : v) {
		cout << mem << "\n";
	}
}