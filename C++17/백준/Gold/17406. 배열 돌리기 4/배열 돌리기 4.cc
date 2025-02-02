#include <iostream>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;
int n, m, k;
int r, c, s;
vector<tuple<int, int, int>> vec;
int arr[51][51];
pair<int, int>direc[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void rotate(int r, int c, int s){
	// r - s , c - s / r + s, c + s
	int left_i = r - s - 1, left_j = c - s - 1;
	int right_i = r + s - 1, right_j = c + s - 1;
	int temp[51][51];
	int gap = right_i - left_i + 1;
	int ni, nj;
	int direc_pos;
	memcpy(temp, arr, sizeof(arr));
	for (int g = 0; g < gap / 2; g++){
		int i = left_i + g;
		int j = left_j + g;
		direc_pos = 0;
		while (true){
			ni = i + direc[direc_pos].first;
			nj = j + direc[direc_pos].second;
			temp[ni][nj] = arr[i][j];
			i = ni;
			j = nj;
			if ((direc_pos == 0 && nj == right_j - g) || (direc_pos == 1 && ni == right_i - g) || (direc_pos == 2 && nj == left_j + g) || (direc_pos == 3 && ni == left_i + g)){
				direc_pos++;
				if (direc_pos == 4) break;
			}
		}
	}
	memcpy(arr, temp, sizeof(arr));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int ret = 987654321;
	int original[51][51];
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> original[i][j];
		}
	}
	for (int i = 0; i < k; i++){
		cin >> r >> c >> s;
		vec.push_back({r, c, s});
	}
	sort(vec.begin(), vec.end());
	do {
		memcpy(arr, original, sizeof(original));
		int a, b, c;
		for (auto mem : vec){
			tie(a,b,c) = mem;
			rotate(a, b, c);
		}
		for (int i = 0; i < n; i++){
			int sumRow = 0;
			for (int j = 0; j < m; j++){
				sumRow += arr[i][j];
			}
			ret = min(ret, sumRow);
		}
	} while (next_permutation(vec.begin(), vec.end()));

	cout << ret;
	return 0;
}
