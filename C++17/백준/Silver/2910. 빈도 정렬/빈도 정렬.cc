#include <bits/stdc++.h>

using namespace std;

int n, c;
int tmp;
map<int , int> mp, mp_first;
vector<pair<int, int>> vc;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return mp_first[a.first] < mp_first[b.first] ;
	return a.second > b.second;
}


int main(void) {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (!mp_first[tmp]) {
			mp_first[tmp] = i + 1;
		}
		if (mp[tmp])
			mp[tmp] += 1;
		else
			mp[tmp] = 1;
	}
	for (auto mem : mp){
		vc.push_back({ mem.first, mem.second });
	}

	sort(vc.begin(), vc.end(), cmp);
	for (auto i : vc) {
		for (int j = 0; j < i.second; j++) {
			cout << i.first << " ";
		}
	}
}