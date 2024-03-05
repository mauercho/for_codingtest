import sys
from collections import deque

input = sys.stdin.readline

def dfs(start):
    print(start, end = ' ')
    visited_dfs[start] = True

    for node in graph[start]:
        if not visited_dfs[node]:
            dfs(node)

def bfs(start):
    q = deque()
    q.append(start)
    visited_bfs[start] = True
    while q:
        a = q.popleft()
        print(a, end = ' ')
        for node in graph[a]:
            if not visited_bfs[node]:
                visited_bfs[node] = True
                q.append(node)


N, M, start = map(int, input().split())
visited_dfs = [False] * (N + 1)
visited_bfs = [False] * (N + 1)
graph = [[] for _ in range(N + 1)]
for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
for i in range(1, N + 1):
    graph[i].sort()

dfs(start)
print()
bfs(start)