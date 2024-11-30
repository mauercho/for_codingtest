import sys

input = sys.stdin.readline

n = int(input())
t_arr = [0] * n
p_arr = [0] * n
dp = [0] * (n + 1)

for i in range(n):
    t_arr[i], p_arr[i] = map(int, input().split())

for i in range(n - 1, -1, -1):
    if t_arr[i] + i <= n:
        dp[i] = max(dp[i + 1], dp[t_arr[i] + i] + p_arr[i])
    else:
        dp[i] = dp[i + 1]
print(dp[0])
