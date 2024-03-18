N = int(input())

dp = [-1] * 5001

dp[3] = 1
dp[5] = 1
for i in range(6, 5001):
    a = 5001
    b = 5001
    if dp[i - 3] != -1:
        a = dp[i - 3] + 1
    if dp[i - 5] != -1:
        b = dp[i - 5] + 1
    if a == 5001 and b == 5001:
        continue
    dp[i] = min(a, b)

print(dp[N])