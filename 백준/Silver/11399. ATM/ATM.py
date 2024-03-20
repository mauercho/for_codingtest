import sys

input = sys.stdin.readline

N = int(input())

arr = list(map(int, input().split()))

arr.sort()
dp = [0] * (N + 1)

sum_val = 0
for i in range(1, N + 1):
    dp[i] = arr[i - 1] + dp[i - 1]
    sum_val += dp[i]
print(sum_val)
 