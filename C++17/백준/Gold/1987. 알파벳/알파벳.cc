#include <iostream>

using namespace std;
int R, C, ret;
char arr[21][21];
const int di[] = { -1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

void go(int y, int x, int num, int cnt){
	ret = max(ret, cnt);
	for (int i = 0; i < 4; i++){
		int ni = y + di[i];
		int nj = x + dj[i];
		if (ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
		int next = (1 << (int)(arr[ni][nj] - 'A'));
		if ((num & next) == 0) go(ni, nj, num | next, cnt + 1);
	}
	return;
}

int main(){
	cin >> R >> C;
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cin >> arr[i][j];
		}
	}
	go(0, 0, 1 << (int)(arr[0][0] - 'A'), 1);
	cout << ret;
	return 0;
}
