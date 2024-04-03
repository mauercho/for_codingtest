import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
arr = []
def do_func(start_i, start_j):
    q = deque()
    cnt = 1
    q.append((start_i, start_j))
    visited[start_i][start_j] = True
    while q:
        i, j = q.popleft()
        for move in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            ni = i + move[0]
            nj = j + move[1]
            if 0 <= ni < N and 0 <= nj < N and not visited[ni][nj] and arr[ni][nj] == 1:
                cnt += 1
                visited[ni][nj] = True
                q.append((ni, nj))
    cnt_lst.append(cnt)


for _ in range(N):
    arr.append(list(map(int, input().rstrip())))

visited = [[False] * N for _ in range(N)]

cnt = 0
cnt_lst = []
for i in range(N):
    for j in range(N):
        if arr[i][j] == 1 and not visited[i][j]:
            do_func(i, j)
            cnt += 1

print(cnt)
cnt_lst.sort()
print(*cnt_lst, sep='\n')