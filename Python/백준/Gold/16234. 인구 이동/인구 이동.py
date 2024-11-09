import sys
from collections import deque
input = sys.stdin.readline

n, l, r = map(int, input().split())
villages = []

for _ in range(n):
    villages.append(list(map(int, input().split())))

cnt = 0

def bfs(temp_i, temp_j):
    global check
    q = deque()
    temp_sum = villages[temp_i][temp_j]
    all_pos = []
    all_pos.append((temp_i, temp_j))
    q.append((temp_i, temp_j))
    while q:
        i, j = q.popleft()
        for move in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            ni = i + move[0]
            nj = j + move[1]
            if not (0 <= ni < n and 0 <= nj < n):
                continue
            if not visited[ni][nj] and l <= abs(villages[i][j] - villages[ni][nj]) <= r:
                check = True
                visited[ni][nj] = True
                all_pos.append((ni, nj))
                q.append((ni, nj))
                temp_sum += villages[ni][nj]
    value = temp_sum // len(all_pos)
    for pos in all_pos:
        villages[pos[0]][pos[1]] = value

while True:
    check = False
    visited = [[False] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if not visited[i][j]:
                visited[i][j] = True
                bfs(i, j)

    if not check:
        break
    cnt += 1

print(cnt)
