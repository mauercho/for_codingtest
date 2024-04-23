import sys

input = sys.stdin.readline

INF = 1e9
def bf():
    for i in range(N):
        for j in range(len(edges)):
            cur_node = edges[j][0]
            next_node = edges[j][1]
            edge_cost = edges[j][2]
            if distance[next_node] > distance[cur_node] + edge_cost:
                distance[next_node] = distance[cur_node] + edge_cost
                if i == N - 1:
                    return True
    return False 

TC = int(input())

for _ in range(TC):
    N, M, W = map(int, input().split())
    edges = []
    distance = [1e9] * (N + 1)
    for _ in range(M):
        a, b, c = map(int, input().split())
        edges.append((a, b, c))
        edges.append((b, a, c))
    for _ in range(W):
        a, b, c = map(int, input().split())
        edges.append((a, b, -c))
    if bf():
        print('YES')
    else:
        print('NO')
    
