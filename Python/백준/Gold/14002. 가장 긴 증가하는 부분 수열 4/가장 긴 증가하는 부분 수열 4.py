import sys

input = sys.stdin.readline

n = int(input())

arr = list(map(int, input().split()))
dp = [1] * (n)
prev = [-1] * (n)
mx = 1
max_idx = 0
for i in range(1, n):
    for j in range(i):
        if arr[j] < arr[i] and dp[i] < dp[j] + 1:
            dp[i] = dp[j] + 1
            if mx < dp[i]:
                mx = dp[i]
                max_idx = i
            prev[i] = j

ans_arr = []
while prev[max_idx] != -1:
    ans_arr.append(arr[max_idx])
    max_idx = prev[max_idx]

ans_arr.append(arr[max_idx])
ans_arr.reverse()
print(mx)
print(*ans_arr)
