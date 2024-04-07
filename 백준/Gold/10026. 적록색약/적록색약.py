import sys
from collections import deque
input = sys.stdin.readline


N = int(input())

visited = [[False] * N for _ in range(N)]
visited1 = [[False] * N for _ in range(N)]

def do_check(start_i, start_j):
    color = arr[start_i][start_j]
    visited[start_i][start_j] = True
    q = deque()
    q.append((start_i, start_j))
    while q:
        i, j = q.popleft()
        for move in [(1, 0), (0, 1),(-1, 0), (0, -1)]:
            ni = i + move[0]
            nj = j + move[1]
            if 0 <= ni < N and 0 <= nj < N and arr[ni][nj] == color and not visited[ni][nj]:
                q.append((ni, nj))
                visited[ni][nj] = True

def do_check1(start_i, start_j):
    color = arr[start_i][start_j]
    if color == 'R' or color == 'G':
        group = ['R', 'G']
    else:
        group = [color]

    visited1[start_i][start_j] = True
    q = deque()
    q.append((start_i, start_j))
    while q:
        i, j = q.popleft()
        for move in [(1, 0), (0, 1),(-1, 0), (0, -1)]:
            ni = i + move[0]
            nj = j + move[1]
            if 0 <= ni < N and 0 <= nj < N and arr[ni][nj] in group and not visited1[ni][nj]:
                q.append((ni, nj))
                visited1[ni][nj] = True

arr = []
for _ in range(N):
    arr.append(list(input().rstrip()))

cnt = 0
cnt1 = 0
for i in range(N):
    for j in range(N):
        if not visited[i][j]:
            do_check(i, j)
            cnt += 1
        if not visited1[i][j]:
            do_check1(i, j)
            cnt1 += 1

print(cnt, cnt1)