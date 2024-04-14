import sys

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

N = int(input())

dp = [[0] * (i + 1) for i in range(N)] # idx N -1 일 때는 N 개 있슴.
arr = []
for _ in range(N):
    arr.append(list(map(int, input().split())))

dp[0] = arr[0]
for i in range(1, N):
    for j in range(i + 1):
        if j == 0:
            dp[i][0] = dp[i - 1][0] + arr[i][0]
        elif j == i:
            dp[i][j] = dp[i - 1][j - 1] + arr[i][j]
        else:
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j]


print(max(dp[N - 1]))