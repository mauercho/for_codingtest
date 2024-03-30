import sys
from collections import deque
input = sys.stdin.readline

def check(start, end):
    q = deque()
    visited = [False] * N
    q.append(start)
    while q:
        temp = q.popleft()
        if temp == end and visited[temp]:
            return True
        for k in range(N):
            if arr[temp][k] and not visited[k]:
                visited[k] = True
                q.append(k)
    return False


N = int(input())
arr = []
for _ in range(N):
    arr.append(list(map(int, input().split())))
can_arr = [[0] * N for _ in range(N)]
for i in range(N):
    for j in range(N):
        if check(i, j):
            can_arr[i][j] = 1

for i in range(N):
    print(*can_arr[i])