import sys

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

def dfs(start, cost):
    global max_distance
    global max_pos

    visited[start] = 1
    if max_distance < cost:
        max_distance = cost
        max_pos = start

    for next, weight in graph[start]:
        if not visited[next]:
            dfs(next, cost + weight)

N = int(input())

graph = [[] for _ in range(N + 1)]
visited = [0] * (N + 1)
for _ in range(N - 1):
    a, b, w = map(int ,input().split())
    graph[a].append((b, w))
    graph[b].append((a, w))

max_distance = 0
max_pos = 0

dfs(1, 0)

visited = [0] * (N + 1)
max_distance = 0
dfs(max_pos, 0)
print(max_distance)
