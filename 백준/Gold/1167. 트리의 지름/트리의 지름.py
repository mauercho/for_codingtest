import sys
# from heapq import heappop, heappush
# sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

def dfs(start, sum_val):
    global farthest_node
    global max_distance
    visited[start] = True

    if sum_val > max_distance:
        max_distance = sum_val
        farthest_node = start
    for node in graph[start]:
        next = node[0]
        dist = node[1]
        if not visited[next]:
            dfs(next, sum_val + dist)


N = int(input())


graph = [[] for _ in range(N + 1)]
visited = [False] * (N + 1)

max_distance = 0
farthest_node = 0
for _ in range(1, N + 1):
    lst = list(map(int, input().split()))
    i = lst[0]
    lst = lst[1: -1]
    for j in range(0, len(lst), 2):
        graph[i].append((lst[j], lst[j + 1]))
        graph[lst[j]].append((i, lst[j + 1]))

dfs(1, 0)
max_distance = 0
visited = [False] * (N + 1)
dfs(farthest_node, 0)
print(max_distance)