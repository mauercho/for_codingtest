#include <bits/stdc++.h>

using namespace std;

int N, K;
int ans = 100001;
int visited[200001];
int prev_arr[200001];

int main() {	
	cin >> N >> K;
	int a;
	vector<int> v;
	if (N == K)
	{
		cout << "0\n" << N;
		return 0;
	}
	queue<int> q;
	q.push(N);
	visited[N] = 1;
	while (q.size()) {
		a = q.front();
		q.pop();
		for (int x : { a + 1, a - 1, 2 * a}) {
			if (0 <= x && x < 200001) {
				if (visited[x] == 0) {
					q.push(x);
					visited[x] = visited[a] + 1;
					prev_arr[x] = a;
				}
			}
		}
	}
	for (int i = K; i != N; i = prev_arr[i]) {
		v.push_back(i);
	}
	v.push_back(N);
	reverse(v.begin(), v.end());
	cout << visited[K] - 1 << "\n";
	for (int i : v) {
		cout << i << " ";
	}
}	