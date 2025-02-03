#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string wheels[1001]; // 1부터 T 까지 탐색
int t, k, d, wheel;
int can[1001];
void rotateAll(int wheelNum, int first_direc){
	// 오른쪽꺼 먼저
	int wheel_right = wheelNum;
	int wheel_left = wheelNum;
	int direc = first_direc;
	fill(can, can + 1001, 0);

	while (wheel_right < t){
		wheel_right++;
		if (wheels[wheel_right][6] != wheels[wheel_right - 1][2]) can[wheel_right] = 1;
		else break;
	}
	while (wheel_left > 1){
		wheel_left--;
		if (wheels[wheel_left][2] != wheels[wheel_left + 1][6]) {
			can[wheel_left] = 1;
		}
		else break;
	}
	wheel_right = wheelNum;
	wheel_left = wheelNum;
	while (wheel_right < t){
		wheel_right++;
		direc *= -1;
		if (can[wheel_right]) { // 다르면 회전함.
			if (direc == 1) rotate(wheels[wheel_right].rbegin(), wheels[wheel_right].rbegin() + 1, wheels[wheel_right].rend());
			else rotate(wheels[wheel_right].begin(), wheels[wheel_right].begin() + 1, wheels[wheel_right].end());
		}
		else {
			break ;
		}
	}
	direc = first_direc;
	while (wheel_left > 1){
		wheel_left--;
		direc *= -1;
		if (can[wheel_left]) {
			if (direc == 1) rotate(wheels[wheel_left].rbegin(), wheels[wheel_left].rbegin() + 1, wheels[wheel_left].rend());
			else rotate(wheels[wheel_left].begin(), wheels[wheel_left].begin() + 1, wheels[wheel_left].end());
		}
		else break;
	}
	if (first_direc == 1) rotate(wheels[wheelNum].rbegin(), wheels[wheelNum].rbegin() + 1, wheels[wheelNum].rend());
	else rotate(wheels[wheelNum].begin(), wheels[wheelNum].begin() + 1, wheels[wheelNum].end());
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int i = 1; i <= t; i++){
		cin >> wheels[i];
	}
	cin >> k;
	for (int i = 0; i < k; i++){
		cin >> wheel >> d;
		rotateAll(wheel ,d);
	}
	int ans = 0;
	for (int i = 1; i <= t; i++){
		if (wheels[i][0] == '1') ans++;
	}
	cout << ans;
	return 0;
}
