#include <bits/stdc++.h>

using namespace std;

const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};
int flag;
int N, L, R, arr[51][51], visited[51][51];

void start(int y, int x) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> vec;
	int ni, nj, i, j;
	int diff;
	int sum_val = arr[y][x];
	int local_cnt = 1;
	q.push({ y, x });;
	visited[y][x] = 1;
	vec.push_back({ y, x });
	while (q.size())
	{
		tie(i, j) = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			ni = i + di[k];
			nj = j + dj[k];
			if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
			if (visited[ni][nj] == 1) continue;
			diff = max(arr[ni][nj], arr[i][j]) - min(arr[ni][nj], arr[i][j]);
			if (diff >= L && diff <= R)
			{
				visited[ni][nj] = 1;
				vec.push_back({ ni, nj });
				q.push({ ni, nj });
				local_cnt += 1;
				sum_val += arr[ni][nj];
				flag = 1;
			}
		}
	}
	int cal_val = sum_val / local_cnt;
	for (auto mem : vec) {
		arr[mem.first][mem.second] = cal_val;
	}
	
}

int main()
{
	int cnt = 0;
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	while (true) {
		flag = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == 0)
				{
					start(i, j);
				}
			}
		}
		if (flag == 0)
		{
			break;
		}
		cnt += 1;
	}
	cout << cnt;
}