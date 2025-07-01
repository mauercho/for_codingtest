#include <iostream>
#include <algorithm>

using namespace std;
int arr[10][10];
int ans = 101;
int paper[6];

int sumpaper(){
	int ret = 0;
	for (int i = 1; i <= 5; i++){
		ret += paper[i];
	}
	return ret;
}

bool is_possible(int a, int b, int sz){
	if (paper[sz] == 5) return false;
	if (a + sz > 10 || b + sz > 10) return false;
	for (int i = 0; i < sz; i++){
		for (int j = 0; j < sz; j++){
			if (arr[i + a][j + b] == 0) return false;
		}
	}
	return true;
}

void mark(int y, int x, int sz){
	int check_num = arr[y][x];
	if (check_num == 1){
		for (int i = 0; i < sz; i++){
			for (int j = 0; j < sz; j++){
				arr[y + i][x + j] = 0;
			}
		}
		paper[sz] += 1;
	}
	else {
		for (int i = 0; i < sz; i++){
			for (int j = 0; j < sz; j++){
				arr[y + i][x + j] = 1;
			}
		}
		paper[sz] -= 1;
	}
}

void backtracking(int i, int j){
	if (i == 10){
		ans = min(ans, sumpaper());
		return ;
	}
	if (j == 10){
		backtracking(i + 1, 0);
		return ;
	}

	if (arr[i][j] == 0){
		backtracking(i, j + 1);
		return ;
	}
	for (int sz = 1; sz < 6; sz++){
		if (is_possible(i, j, sz)){
			mark(i, j, sz);
			backtracking(i, j + 1);
			mark(i, j, sz);
		}
	}
}

int main(){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			cin >> arr[i][j];
		}
	}
	backtracking(0, 0);

	if (ans == 101){
		cout << -1;
	}
	else {
		cout << ans;
	}
	return 0;
}
