#include <bits/stdc++.h>

using namespace std;

int h, w;

int arr[100][100];
string s;

int main() {
	cin >> h >> w;
	

	for (int i = 0; i < h; i++) {
		cin >> s;
		for (int j = 0; j < w; j++) {
			if (s[j] == 'c') {
				arr[i][j] = 0;
			}
			else {
				if (j == 0) {
					arr[i][j] = -1;
				}
				else {
					if (arr[i][j - 1] >= 0) {
						arr[i][j] = arr[i][j - 1] + 1;
					}
					else {
						arr[i][j] = -1;
					}
				}
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}
