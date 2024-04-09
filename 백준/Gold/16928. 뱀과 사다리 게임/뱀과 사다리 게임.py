import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

N, M = map(int, input().split())

def do_dfs(start, cnt):
    global ans

    if cnt >= ans:
        return
    if start > 100:
        return
    if start == 100:
        ans = min(ans, cnt)
        return
    if dp[start] <= cnt:
        return
    dp[start] = cnt 
    for gap in range(1, 7):
        if start + gap in ladder_d.keys():
            do_dfs(ladder_d[start + gap], cnt + 1)
        elif start + gap in snake_d.keys():
            do_dfs(snake_d[start + gap], cnt + 1)
        else:
            do_dfs(start + gap, cnt + 1)
    

ladder_d = dict()
snake_d = dict()

dp = [float('inf')] * 101
for _ in range(N):
    a, b = map(int, input().split())
    ladder_d[a] = b
for _ in range(M):
    a, b = map(int, input().split())
    snake_d[a] = b

ans = float('inf')

do_dfs(1, 0)
print(ans)