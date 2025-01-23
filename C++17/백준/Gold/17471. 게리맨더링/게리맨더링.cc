#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n;
int popularity[11];
int graph[11][11];
int visited[11];
int check[11];
int cnt_a, cnt_b, sum_a, sum_b;
int flag = 0;
int ans = 987654321;
int zero_pos, one_pos;

void bfs(int start, int z){

    queue<int> q;
    q.push(start);
    visited[start] = 1;
    int now;
    if (z == 0)
    {
        sum_a += popularity[start];
        cnt_a++;
    }
    else if (z == 1)
    {
        cnt_b++;
        sum_b += popularity[start];
    }
    while (q.size()){
        now = q.front(); q.pop();
        for (int next = 1; next <= n; next++){
            if (visited[next] == 0 && graph[now][next] == 1 && check[next] == z){
                if (z == 0)
                {
                    sum_a += popularity[next];
                    cnt_a++;
                    visited[next] = 1;
                }
                else if (z == 1)
                {
                    sum_b += popularity[next];
                    cnt_b++;
                    visited[next] = 1;
                }
                q.push(next);
            }
        }
    }
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> popularity[i];
    }
    int tmp;
    int k;
    for (int i = 1; i <= n; i++){
        cin >> tmp;
        for (int j = 1; j <= tmp; j++){
            cin >> k;
            graph[i][k] = 1;
        }
    }
    // 여기까지 input 다 받았음.
    for (int num = 1; num < (1 << n) - 1; num++){
        fill(visited, visited + 11, 0);
        fill(check, check + 11, 0);
        flag = 0;
        cnt_a = cnt_b = sum_a = sum_b = 0;

        for (int c = 0; c < n; c++){
            if (num & (1 << c)) {
                check[c + 1] = 1;
                one_pos = c + 1;
            }
            else {
                zero_pos = c + 1;
            }
        }
        bfs(zero_pos, 0);
        bfs(one_pos, 1);
        if (cnt_a + cnt_b == n){
            ans = min(ans, abs(sum_a - sum_b));
        }
        else continue;
    }

    cout << (ans == 987654321 ? -1 : ans);
}
