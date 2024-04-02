import sys
from collections import deque

input = sys.stdin.readline

M, N, H = map(int, input().split())

def bfs():
    global ans

    while q:
        h, c, r, val = q.popleft()
        for move in [(1, 0, 0), (-1, 0, 0), (0, 1, 0), (0, -1, 0), (0, 0, 1), (0, 0, -1)]:
            nh = h + move[0]
            nc = c + move[1]
            nr = r + move[2]
            if 0 <= nh < H and 0 <= nc < N and 0 <= nr < M:
                if arr[nh][nc][nr] == 0:
                    arr[nh][nc][nr] = val + 1
                    ans = max(ans, val + 1)
                    q.append((nh, nc, nr, val + 1))

def check():
    for k in range(H):
        for i in range(N):
            for j in range(M):
                if arr[k][i][j] == 0:
                    return True
    return False

arr = []
q = deque()
for k in range(H):
    temp = []
    for i in range(N):
        lst = list(map(int, input().split()))
        for j in range(M):
            if lst[j] == 1:
                q.append((k, i, j, 0))  # 높 가 세 
        temp.append(lst)
    arr.append(temp)

ans = 0

bfs()
if check():
    print(-1)
else:
    print(ans)
                
        


