#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[100][100];

const int di[4] = { 1, 0, -1, 0 };
const int dj[4] = { 0, 1, 0, -1 };
int cnt;

void start(int a, int b)
{
	int i, j;
	int ni, nj;

	queue<pair<int, int>> q;
	q.push({ a, b });
	arr[a][b] = -1;
	cnt += 1;
	while (!q.empty())
	{
		i = q.front().first;
		j = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			ni = i + di[k];
			nj = j + dj[k];
			if (0 <= ni && ni < N && 0 <= nj && nj < M)
			{
				if (arr[ni][nj] == 0)
				{
					arr[ni][nj] = -1;
					q.push({ ni, nj });
					cnt += 1;
				}
			}
		}
	}
}

int main()
{
	int num = 0;
	int first_check = 0;
	int ans = 0;
	int z, x;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	start(0, 0);

	while (1) {
		stack<pair<int, int>> stk;
		first_check = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arr[i][j] == 1 && (arr[i + 1][j] == -1 || arr[i][j - 1] == -1 || arr[i - 1][j] == -1 || arr[i][j + 1] == -1))
				{
					if (first_check == 0)
					{
						num += 1;
						first_check = 1;
					}
					stk.push({ i, j });
				}
			}
		}
		ans = stk.size();
		while (!stk.empty()) {
			tie(z, x) = stk.top();
			stk.pop();
			start(z, x);
		}
		if (cnt == N * M)
		{
			break;
		}
	}
	cout << num << "\n";
	cout << ans;
}