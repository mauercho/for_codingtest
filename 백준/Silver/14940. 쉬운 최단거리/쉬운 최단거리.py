import sys
from collections import deque

input = sys.stdin.readline

def bfs(start_i, start_j):
    q = deque()
    arr1[start_i][start_j] = 0
    q.append((start_i, start_j, 0))
    visited[start_i][start_j] = True
    while q:
        i, j, cnt = q.popleft()
        for move in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            ni = i + move[0]
            nj = j + move[1]
            if not (0 <= ni < n and 0 <= nj < m):
                continue
            if arr[ni][nj] == 1 and not visited[ni][nj]:
                visited[ni][nj] = True
                q.append((ni, nj, cnt + 1))
                arr1[ni][nj] = cnt + 1

    for i in range(n):
        for j in range(m):
            if arr[i][j] == 0:
                arr1[i][j] = 0

n, m = map(int, input().split())

arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))


for i in range(n):
    if 2 in arr[i]:
        start_j = arr[i].index(2)
        start_i = i
        break
arr1 = [[-1] * m for _ in range(n)]
visited = [[False] * m for _ in range(n)]

bfs(start_i, start_j)
for i in range(n):
    print(*arr1[i])