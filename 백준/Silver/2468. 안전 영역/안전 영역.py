import sys
sys.setrecursionlimit(10**6)

input = sys.stdin.readline

ans = 1

def is_valid(i, j):
    return 0 <= i < N and 0 <= j < N 

def change(i, j, height):
    di = (1, 0, -1, 0)
    dj = (0, 1, 0, -1)
    visited[i][j] = True

    for k in range(4):
        ni = i + di[k]
        nj = j + dj[k]
        if is_valid(ni, nj) and array[ni][nj] - height > 0 and not visited[ni][nj]:
            change(ni, nj, height)

def check(height):
    global ans
    temp = 0
    for i in range(N):
        for j in range(N):
            if not visited[i][j] and array[i][j] - height > 0:
                change(i, j, height)
                temp += 1
    ans = max(ans, temp)


N = int(input())

array = [list(map(int, input().split())) for _ in range(N)]

for height in range(1, 101):
    visited = [[False] * N for _ in range(N)]
    check(height)

print(ans)