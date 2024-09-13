#include <bits/stdc++.h>

using namespace std;
int N, K;
int ans = 100001;
int visited[200001];
int cnt[200001];

int main() {	
	cin >> N >> K;
	int a;
	if (N == K)
	{
		cout << "0\n" << "1";
		return 0;
	}
	queue<int> q;
	q.push(N);
	visited[N] = 1;
	cnt[N] = 1;
	while (q.size()) {
		a = q.front();
		q.pop();
		for (int x : { a + 1, a - 1, 2 * a}) {
			if (0 <= x && x < 200001) {
				if (visited[x] == 0) {
					q.push(x);
					visited[x] = visited[a] + 1;
					cnt[x] += cnt[a];
				}
				else if (visited[x] == visited[a] + 1) {
					cnt[x] += cnt[a];
				}
			}
		}
	}
	cout << visited[K] - 1 << "\n";
	cout << cnt[K];
}