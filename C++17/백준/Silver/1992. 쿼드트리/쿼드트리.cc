#include <bits/stdc++.h>

using namespace std;

int n;

int arr[65][65];

int check(int a, int b, int x) {
	int chk = arr[a][b];

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			if (chk != arr[a + i][b + j]) {
				return 0;
			}
		}
	}
	return 1;
}

void do_thing(int i, int j, int x) {
	
	if (check(i, j, x)) {
		cout << arr[i][j];
	}
	else {
		cout << "(";
		do_thing(i, j, x / 2);
		do_thing(i, j + x / 2, x / 2);
		do_thing(i + x / 2, j, x / 2);
		do_thing(i + x / 2, j + x / 2, x / 2);
		cout << ")";
	}
	
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	do_thing(0, 0, n);
}