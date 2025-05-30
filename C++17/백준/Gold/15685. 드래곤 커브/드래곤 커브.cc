#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int arr[102][102];

pair<int, int> directions[4] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

vector<vector<int>> v(4);

void start(int num){
	v[num].push_back(num);
	for (int i = 1; i <= 10; i++){
		int size = v[num].size();
		for (int i = size - 1; i >=0 ; i--){
			v[num].push_back((v[num][i] + 1) % 4);
		}
	}
}

void fill_arr(int x, int y, int d, int g){
	int sx = x;
	int sy = y;
	arr[sx][sy] = 1;
	for (int i = 0; i < int(pow(2, g)); i++){
		sx += directions[v[d][i]].first;
		sy += directions[v[d][i]].second;
		arr[sx][sy] = 1;
	}
}

int n;
int x, y, d, g;
int main(){
	int num_cnt = 0;
	cin >> n;
	for (int i = 0; i < 4; i++){
		start(i);
	}
	for (int i = 0; i < n; i++){
		cin >> x >> y >> d >> g;
		fill_arr(x, y, d, g);
	}
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			if (arr[i][j] == 1 && arr[i][j + 1] == 1 && arr[i + 1][j] == 1 && arr[i + 1][j + 1] == 1) num_cnt += 1;
		}
	}
	cout << num_cnt;
	return 0;
}
