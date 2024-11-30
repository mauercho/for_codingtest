import sys

input = sys.stdin.readline

n = int(input())

arr = list(map(int, input().split()))
dp = [0] * (n + 1)


arr = [0] + arr
for i in range(1, n + 1):
    mx = 0
    for j in range(i):
        if arr[j] > arr[i]:
            mx = max(mx, dp[j])
    dp[i] = mx + 1

mx = max(dp)
print(n - mx)
