import sys

input = sys.stdin.readline

def dfs(depth, sum_val):
    global ans
    if depth >= n:
        ans = max(ans, sum_val)
        return
    if t_arr[depth] + depth <= n:
        dfs(depth + t_arr[depth], sum_val + p_arr[depth])
    dfs(depth + 1, sum_val)

n = int(input())
ans = 0
t_arr = [0] * n
p_arr = [0] * n

for i in range(n):
    t_arr[i], p_arr[i] = map(int, input().split())

dfs(0, 0)

print(ans)
