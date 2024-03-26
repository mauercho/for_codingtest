import sys
from collections import deque

input = sys.stdin.readline

def bfs(start_i, start_j):
    global cnt

    q = deque()
    q.append((start_i, start_j))
    while q:
        i, j = q.popleft()
        for move in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            ni = i + move[0]
            nj = j + move[1]
            if 0 <= ni < n and 0 <= nj < m and arr[ni][nj] != 'X' and not visited[ni][nj]:
                q.append((ni, nj))
                visited[ni][nj] = True
                if arr[ni][nj] == 'P':
                    cnt += 1

n, m = map(int, input().split())
arr = []
for i in range(n):
    string = input().rstrip()
    if 'I' in string:
        start_j = string.index('I')
        start_i = i
    arr.append(string)

visited = [[False] * m for _ in range(n)]
visited[start_i][start_j] = True
cnt = 0
bfs(start_i, start_j)
if cnt > 0:
    print(cnt)
else:
    print("TT")