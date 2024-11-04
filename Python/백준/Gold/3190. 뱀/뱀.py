import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
K = int(input())

board = [[0] * N for _ in range(N)]
time = 0
for _ in range(K):
    a, b = map(lambda x : x - 1, map(int, input().split()))
    board[a][b] = 1

L = int(input())
turns = deque()
for _ in range(L):
    turns.append(list(input().rstrip().split()))

# move -> time++ -> check apple -> check gameover

moves = [(0, 1), (1, 0), (0, - 1), (-1, 0)]
move_idx = 0
gummy = [(0, 0)]

while True:
    if turns and int(turns[0][0]) == time:
        if turns[0][1] == 'L':
            if move_idx == 0:
                move_idx = 3
            else:
                move_idx -= 1
        else:
            if move_idx == 3:
                move_idx = 0
            else:
                move_idx += 1
        turns.popleft()

    a = gummy[0][0] + moves[move_idx][0]
    b = gummy[0][1] + moves[move_idx][1]
    time += 1
    if (a, b) in gummy or not (0 <= a < N) or not (0 <= b < N):
        print(time)
        break
    gummy = [(a, b)] + gummy
    if board[a][b] == 1:
        board[a][b] = 0
    else:
        gummy.pop()


