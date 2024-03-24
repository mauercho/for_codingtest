import sys
from collections import deque

def bfs(start):
    q = deque()
    q.append(start)
    cnt = 0
    visited[start] = True
    while q:
        new = q.popleft()
        for node in graph[new]:
            if not visited[node]:
                visited[node] = True
                q.append(node)
                cnt += 1
    return cnt




input = sys.stdin.readline

num = int(input())

edge = int(input())

visited = [False] * (num + 1)
graph = [[] for _ in range(num + 1)]


for _ in range(edge):
    a,b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

print(bfs(1))
