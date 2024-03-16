N, K = map(int, input().split())

dp = [0] * 11

dp[0] = 1
dp[1] = 1
for i in range(2, 11):
    dp[i] = dp[i - 1] * i

print(int((dp[N] / dp[N - K]) / dp[K]))
