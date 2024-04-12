import sys
from collections import deque

def bfs(start):
    q = deque()
    q.append(start)
    visited[start] = True
    while q:
        node = q.popleft()
        for new in graph[node]:
            if not visited[new]:
                visited[new] = True
                q.append(new)
                parent[new] = node
    


input = sys.stdin.readline

N = int(input())

parent = [-1] * (N + 1)
graph = [[] for _ in range(N + 1)]
visited = [False] * (N + 1)

for _ in range(N - 1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

bfs(1)
print(*parent[2:], sep='\n')