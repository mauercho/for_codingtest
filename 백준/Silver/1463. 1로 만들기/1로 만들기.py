import sys

input = sys.stdin.readline

N = int(input())
dp = [0] * (N + 1)
dp[1] = 0
for i in range(2, N + 1):
    a = N + 1
    b = N + 1
    if i % 3 == 0:
        a = dp[i // 3] + 1
    if i % 2 == 0:
        b = dp[i // 2] + 1
    dp[i] = min(dp[i - 1] + 1, a, b)

print(dp[N])