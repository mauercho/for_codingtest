import sys
from collections import deque

input = sys.stdin.readline

M, N = map(int, input().split())
arr = []
q = deque()
max_val = 1
visited = [[False] * M in range(N)]
for i in range(N):
    lst = list(map(int, input().split()))
    for j in range(len(lst)):
        if lst[j] == 1:
            q.append((i, j))
    arr.append(lst)




while q:
    i, j = q.popleft()
    val = arr[i][j]
    for move in [(1,0),(0,1),(-1, 0), (0, -1)]:
        ni = i + move[0]
        nj = j + move[1]
        if not (0 <= ni < N and 0 <= nj < M):
            continue
        if arr[ni][nj] == 0:
            arr[ni][nj] = val + 1
            max_val = max(max_val, val + 1)
            q.append((ni,nj))

for i in range(N):
    if 0 in arr[i]:
        print(-1)
        break
else:
    print(max_val - 1)
        
