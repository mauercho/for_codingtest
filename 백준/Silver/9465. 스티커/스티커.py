import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())
    arr = []
    for _ in range(2):
        lst = [0] + list(map(int, input().split()))
        arr.append(lst)
    dp = [[0] * (N + 1) for _ in range(2)]
    dp[0][1] = arr[0][1]
    dp[1][1] = arr[1][1]
    for j in range(2, N + 1):
        dp[0][j] = max(dp[0][j -2], dp[1][j - 2], dp[1][j - 1]) + arr[0][j] 
        dp[1][j] = max(dp[0][j - 2], dp[1][j - 2], dp[0][j - 1]) + arr[1][j]
    print(max(dp[0][-1], dp[1][-1], dp[0][-2], dp[1][-2]))