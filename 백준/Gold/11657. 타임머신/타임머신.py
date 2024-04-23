import sys

input = sys.stdin.readline

INF = 1e9
N, M = map(int, input().split())

def bf(start):
    distance[start] = 0

    for i in range(N):
        for j in range(len(edges)):
            cur, next, w = edges[j]
            if distance[cur] != INF and distance[next] > distance[cur] + w:
                distance[next] = distance[cur] + w

                if i == N - 1:
                    return True
    return False


distance = [INF] * (N + 1)

edges = []

for _ in range(M):
    a, b, w = map(int,input().split())
    edges.append((a, b, w))

if bf(1):
    print(-1)
else:
    for i in range(2, N + 1):
        if distance[i] >= INF:
            print(-1)
        else:
            print(distance[i])