import sys
from collections import deque
input = sys.stdin.readline


T = int(input())

def do_check(start_i, start_j):
    q = deque()
    q.append((start_i, start_j))
    visited[start_i][start_j] = True
    while q:
        i, j = q.popleft()
        for move in [(1, 0),(0, 1),(0, -1), (-1, 0)]:
            ni = i + move[0]
            nj = j + move[1]
            if 0 <= ni < N and 0 <= nj < M and graph[ni][nj] == 1 and not visited[ni][nj]:
                visited[ni][nj] = True
                q.append((ni, nj))



def dfs():
    global cnt
    for i in range(N):
        for j in range(M):
            if graph[i][j] == 1 and not visited[i][j]:
                do_check(i, j)
                cnt += 1

arr =[]
for _ in range(T):
    M, N, K = map(int, input().split())
    graph = [[0] * M for k in range(N)]
    visited = [[False] * M for t in range(N)]
    for l in range(K):
        b, a = map(int, input().split())
        graph[a][b] = 1
    cnt = 0
    dfs()
    print(cnt)


