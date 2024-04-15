import sys

input = sys.stdin.readline
N, M = map(int, input().split())
arr = [[0] * (N + 1)] + [[0] + list(map(int, input().split())) for _ in range(N)] 
sum_val = [[0] * (N + 1) for _ in range(N + 1)]

for i in range(1, N + 1):
    for j in range(1, N + 1):
        sum_val[i][j] = arr[i][j] + sum_val[i - 1][j] + sum_val[i][j - 1] - sum_val[i - 1][j - 1]


for _ in range(M):
    ans = 0
    x1, y1, x2, y2 = map(int, input().split())
    ans = sum_val[x2][y2] - sum_val[x1 - 1][y2] - sum_val[x2][y1 - 1] + sum_val[x1 - 1][y1 - 1]

    print(ans)