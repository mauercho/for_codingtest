from collections import deque
import sys

input = sys.stdin.readline
n, m, k, x = map(int, input().split())

graph = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)

ans_arr = []
visited = [False] * (n + 1)

def bfs(start):
    q = deque()
    visited[start] = True
    q.append((x, 0))
    while q:
        now, dist = q.popleft()
        if dist == k:
            ans_arr.append(now)
        if dist > k:
            break
        for mem in graph[now]:
            if visited[mem]:
                continue
            visited[mem] = True
            q.append((mem , dist + 1))

bfs(x)

if len(ans_arr) == 0:
    print(-1)
else:
    for mem in sorted(ans_arr):
        print(mem)
