import sys
input = sys.stdin.readline

def find_parent(parent, a):
    if parent[a] != a:
        parent[a] = find_parent(parent, parent[a])
    return parent[a]

def get_union(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

a_edge = []
b_edge = []
c_edge = []
n = int(input())

parent = [0] * (n)
for i in range(n):
    parent[i] = i
for i in range(n):
    a, b, c = map(int, input().split())
    a_edge.append((a, i))
    b_edge.append((b, i))
    c_edge.append((c, i))

edges = []

a_edge.sort()
b_edge.sort()
c_edge.sort()

for i in range(n - 1):
    edges.append((a_edge[i + 1][0] - a_edge[i][0], a_edge[i][1], a_edge[i + 1][1]))
    edges.append((b_edge[i + 1][0] - b_edge[i][0], b_edge[i][1], b_edge[i + 1][1]))
    edges.append((c_edge[i + 1][0] - c_edge[i][0], c_edge[i][1], c_edge[i + 1][1]))


edges.sort()
ans = 0
cnt = 0
for edge in edges:
    dist, x, y = edge
    if find_parent(parent, x) != find_parent(parent, y):
        get_union(parent, x, y)
        ans += dist
        cnt += 1
        if cnt == n - 1:
            break
print(ans)
