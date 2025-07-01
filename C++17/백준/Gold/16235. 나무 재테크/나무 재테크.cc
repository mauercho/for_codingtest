#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int di[] = {1, -1, 0, 0, 1, -1, -1, 1};
const int dj[] = {0, 0, 1, -1, 1, -1, 1, -1};
int n, m, k;
vector<int> arr[11][11];
int yangbun[11][11];
int a[11][11];

void springSummer(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (arr[i][j].empty()) continue;
			vector<int> temp;
			int die_tree = 0;
			sort(arr[i][j].begin(), arr[i][j].end());
			for (auto mem: arr[i][j]){
				if (mem <= yangbun[i][j]){
					yangbun[i][j] -= mem;
					temp.push_back(mem + 1);
				}
				else {
					die_tree += mem / 2;
				}
			}
			arr[i][j] = temp;
			yangbun[i][j] += die_tree;
		}
	}
}

void fall(){
	vector<pair<int, int>> temp;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (arr[i][j].empty()) continue;
			for (auto mem: arr[i][j]){
				if (mem % 5 == 0){
					for (int k = 0; k < 8; k++){
						int ni = i + di[k];
						int nj = j + dj[k];
						if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
						temp.push_back({ni, nj});
					}
				}
			}
		}
	}
	for (pair<int, int>mem : temp){
		arr[mem.first][mem.second].push_back(1);
	}
}

void winter(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			yangbun[i][j] += a[i][j];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	fill(&yangbun[0][0], &yangbun[0][0] + 11 * 11, 5);
	cin >> n >> m >> k;
	int year = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < m; i++){
		int x, y, age;
		cin >> x >> y >> age;
		arr[x-1][y-1].push_back(age);
	}
	while (year < k){
		springSummer();
		fall();
		winter();
		year++;
	}
	int ans = 0;
	for (int i = 0; i < n; i++){
		for (int j= 0; j < n; j++){
			ans += arr[i][j].size();
		}
	}
	cout << ans;
	return 0;
}
