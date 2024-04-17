import sys

input = sys.stdin.readline

def find_parent(x, parent):
    if parent[x] != x:
        parent[x] = find_parent(parent[x], parent)
    return parent[x]

def union_parent(a, b, parent):
    a = find_parent(a, parent)
    b = find_parent(b, parent)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b

N = int(input())
parent = [0] * (N + 1)
for i in range(1, N + 1):
    parent[i] = i

M = int(input())
edges = []
for _ in range(M):
    a, b, dist = map(int, input().split())
    edges.append((dist, a, b))

edges.sort()

sum_val = 0
cnt = 0
for edge in edges:
    dist, a, b = edge
    if find_parent(a, parent) != find_parent(b, parent):
        union_parent(a, b, parent)
        cnt += 1
        sum_val += dist
        if cnt == N - 1:
            break

print(sum_val)