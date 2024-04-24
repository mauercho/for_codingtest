import sys
from heapq import heappop, heappush
input = sys.stdin.readline

INF = 1e9
N, M = map(int, input().split())
distance1 = [INF] * (N + 1)
distance2 = [INF] * (N + 1)

graph = [[] for _ in range(N + 1)]

def dijkstra(start, arr):
    arr[start] = 0 
    pq = []
    heappush(pq, (0, start))
    while pq:
        dist, now = heappop(pq)

        if arr[now] < dist:
            continue
        for next, w in graph[now]:
            cost = arr[now] + w

            if cost < arr[next]:
                arr[next] = cost
                heappush(pq, (cost, next))

for _ in range(M):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

v1, v2 = map(int, input().split())

dijkstra(v1, distance1) # distance1은 v1 전용
dijkstra(v2, distance2) # distance2는 v2 전용

ans1 = distance1[1] + distance1[v2] + distance2[N]
ans2 = distance2[1] + distance2[v1] + distance1[N]

if ans1 >= INF and ans2 >= INF:
    print(-1)
else:
    print(min(ans1, ans2))