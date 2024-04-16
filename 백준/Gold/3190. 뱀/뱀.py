from collections import deque
import sys

input = sys.stdin.readline

N = int(input())
arr = [[0] * N for _ in range(N)]

K = int(input())
for _ in range(K):
    a, b = map(lambda x:x - 1, map(int,input().split()))
    arr[a][b] = 1

L = int(input())

di = (0, 1, 0, -1)
dj = (1, 0, -1, 0)


moves = deque()
for _ in range(L):
    a, b = input().split()
    moves.append((int(a), b))

direc = 0 
time = 0
i, j = 0, 0
q = deque([(0, 0)]) 
while True:
    ni = i + di[direc]
    nj = j + dj[direc]
    time += 1
    if 0 <= ni < N and 0 <= nj < N and (ni, nj) not in q:
        i = ni
        j = nj
    else:
        break
    q.append((i, j))
    if arr[i][j] != 1: # 사과 아닐때는 맨 앞 빼줘야함.
        q.popleft()
    else: # 사과임.
        arr[i][j] = 0
    if moves and moves[0][0] == time:
        if moves[0][1] == 'D':
            direc = (direc + 1) % 4
        else:
            direc = (direc - 1) % 4
        moves.popleft()

print(time)