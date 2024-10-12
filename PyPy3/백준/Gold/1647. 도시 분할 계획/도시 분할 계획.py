def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

n, m = map(int, input().split())

edges = []
parent = [0] * (n + 1)
result = 0
for i in range(1, n + 1):
    parent[i] = i

for _ in range(m):
    a, b, cost = map(int, input().split())
    edges.append((cost, a, b))

edges.sort()
last = 0
cnt = 0
for edge in edges:
    co, x, y = edge
    if find_parent(parent, x) != find_parent(parent, y):
        cnt += 1
        union_parent(parent, x, y)
        last = co
        result += co
        if cnt == n - 1:
            break

print(result - last)
