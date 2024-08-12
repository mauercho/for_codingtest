#include <bits/stdc++.h>

using namespace std;

int n, m, j;
vector<int> arr;
int main() {
	cin >> n >> m;
	cin >> j;
	int move = 0;
	int start = 1;
	int num;
	for (int i = 0; i < j; i++) {
		cin >> num;
		arr.push_back(num);
	}
	for (int mem : arr) {
		if (start < mem) {
			while (start + m - 1 < mem) {
				start += 1;
				move += 1;
			}
		}
		else {
			while (start > mem) {
				start -= 1;
				move += 1;
			}
		}
	}
	cout << move;
}