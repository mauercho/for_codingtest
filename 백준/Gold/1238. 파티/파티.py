import sys
from heapq import heappop, heappush

input = sys.stdin.readline

def dikjstra(start):
    pq = []
    distance[start] = 0
    heappush(pq, (0, start))
    while pq:
        dist, now = heappop(pq)
        if dist > distance[now]:
            continue
        for x, w in graph[now]:
            cost = dist + w
            if cost < distance[x]:
                distance[x] = cost
                heappush(pq, (cost, x))
    return distance

N, M, X = map(int, input().split())

graph = [[] for _ in range(N + 1)]
result = [[]]

for _ in range(M):
    a, b, cost = map(int, input().split())
    graph[a].append((b, cost))

for i in range(1, N + 1):
    distance = [float('inf')] * (N + 1)
    dikjstra(i)
    result.append(distance)

max_val = 0
for i in range(1, N + 1):
    max_val = max(result[i][X] + result[X][i], max_val)

print(max_val)