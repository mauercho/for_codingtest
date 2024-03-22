from collections import deque

import sys

def bfs(start_i, start_j):
    q= deque()
    q.append((start_i, start_j))

    while q:
        i, j = q.popleft()
        for move in [[1, 0], [0, 1], [0, -1], [-1, 0]]:
            ni = i + move[0]
            nj = j + move[1]

            if not (0 <= ni < N and 0 <= nj < M):
                continue
            if distance[ni][nj] <= distance[i][j] + int(arr[ni][nj]):
                continue
            distance[ni][nj] = distance[i][j] + int(arr[ni][nj])
            q.append((ni, nj))


input = sys.stdin.readline

INF = int(1e9)



M, N = map(int, input().split())
arr =[]

distance = [[INF] * M for _ in range(N)] 
for i in range(N):
    arr.append(input().rstrip())

distance[0][0] = 0
bfs(0,0)
print(distance[N - 1][M - 1])

