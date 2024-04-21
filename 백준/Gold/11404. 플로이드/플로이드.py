import sys
from heapq import heappop, heappush
input = sys.stdin.readline

N = int(input())
M = int(input())

graph = [[float('inf')] * N for _ in range(N)]

for i in range(N):
    graph[i][i] = 0

for _ in range(M):
    a, b, c = map(int, input().split())
    if graph[a - 1][b - 1] > c:
        graph[a - 1][b - 1] = c

for k in range(N):
    for a in range(N):
        for b in range(N):
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])

for a in range(N):
    for b in range(N):
        if graph[a][b] >= float('inf'):
            graph[a][b] = 0

for i in range(N):
    print(*graph[i])