import sys
input = sys.stdin.readline

N = int(input())

dp = [1] * N
arr = list(map(int, input().split()))

length = len(arr)

max_val = 1
for i in range(length):
    for j in range(i):
        if arr[i] > arr[j]:
            dp[i] = max(dp[i], dp[j] + 1)
            max_val = max(max_val , dp[i])
print(max_val)
