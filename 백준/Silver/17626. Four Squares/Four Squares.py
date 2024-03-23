import math

N = int(input())

dp = [0] * (N + 1)
dp[1] = 1

for i in range(2, N + 1):
    min_val = 100000
    for j in range(1, int(math.sqrt(i)) + 1):
        min_val = min(min_val, dp[i - j ** 2] + 1)
    dp[i] = min_val

print(dp[N])