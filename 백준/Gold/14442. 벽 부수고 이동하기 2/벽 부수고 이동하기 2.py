import sys
from collections import deque
input = sys.stdin.readline

def bfs():
    q = deque()
    q.append((0, 0, 1, 0))  
    visited[0][0][0] = True
    while q:
        i, j, cnt, K_cnt = q.popleft()
        if i == N - 1 and j == M - 1:
            return cnt
        for move in [(1, 0),(0, 1), (-1, 0), (0, -1)]:
            ni = i + move[0]
            nj = j + move[1]
            if K_cnt < K:
                if 0 <= ni < N and 0 <= nj < M: 
                    if not visited[ni][nj][K_cnt] and arr[ni][nj] == '0':
                        visited[ni][nj][K_cnt] = True
                        q.append((ni, nj, cnt + 1, K_cnt))
                    elif not visited[ni][nj][K_cnt + 1] and arr[ni][nj] == '1':
                        visited[ni][nj][K_cnt + 1] = True
                        q.append((ni,nj,cnt + 1, K_cnt + 1))
            else: # 벽 뚫고 갔음.
                if 0 <= ni < N and 0 <= nj < M:
                    if not visited[ni][nj][K_cnt] and arr[ni][nj] == '0':
                        visited[ni][nj][K_cnt] = True
                        q.append((ni,nj,cnt + 1, K_cnt))                

    return -1

N, M, K = map(int, input().split())

arr = []
for _ in range(N):
    arr.append(input().rstrip())

visited = [[[False] * (K + 1) for _ in range(M)] for _ in range(N)]   # 3차원 visited 임. 마지막에는 벽돌 뚫고간 횟수.

print(bfs())