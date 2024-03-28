import sys
from heapq import heappop, heappush
import math

input = sys.stdin.readline

def bfs(start_i, start_j):
    pq = []
    heappush(pq, (arr[0][0], start_i, start_j))

    while pq:
        dist, i, j = heappop(pq)
        if dist > distance[i][j]:
            continue
        for move in [(1, 0), (0, 1),(-1, 0), (0, -1)]:
            ni = i + move[0]
            nj = j + move[1]
            if not (0 <= ni < N and 0 <= nj < N):
                continue
            cost = dist + arr[ni][nj]
            if cost < distance[ni][nj]:
                distance[ni][nj] = cost
                heappush(pq, (cost, ni, nj))

    return distance[N - 1][N - 1]

cnt = 1
while True:
    N = int(input())
    if N == 0:
        break
    arr = []
    for _ in range(N):
        arr.append(list(map(int, input().split())))
    distance = [[math.inf] * N for _ in range(N)]
    distance[0][0] = arr[0][0]
    print(f"Problem {cnt}: {bfs(0, 0)}")
    cnt += 1


