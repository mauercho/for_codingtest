import heapq
v,e = map(int, input().split())



def prim(start):
    q = [(0, start)]
    visited = [0] * (v + 1)
    answer = 0
    while q:
        dist, now = heapq.heappop(q)
        if visited[now]:
            continue
        visited[now] = True
        answer += dist
        for next, weight in graph[now]:
            if not visited[next]:
                heapq.heappush(q, (weight, next))

    return answer

graph = [[] for _ in range(v + 1)]
for _ in range(e):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))




print(prim(1))
