import sys
from heapq import heappush, heappop

input = sys.stdin.readline

def dijkstra(start):
    q = []
    heappush(q, (0, start))
    while q:
       dist, now = heappop(q)
       if distance[now] < dist:
           continue
       for i in graph[now]:
           cost = dist + i[1]
           if cost < distance[i[0]]:
               distance[i[0]] = cost
               heappush(q, (cost, i[0]))

V, E = map(int, input().split())
INF = (1e9)
start = int(input())
distance = [float('inf')] * (V + 1)
distance[start] = 0

graph = [[] for _ in range(V + 1)]

for _ in range(E):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))

dijkstra(start)

for i in range(1, V + 1):
    if distance[i] == float('inf'):
        print('INF')
    else:
        print(distance[i])
