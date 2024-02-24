from collections import deque

def is_valid(i, j):
    return 0 <= i < a and 0 <= j < b

K = int(input())
W, H = map(int, input().split())
start_i, start_j = 0, 0
a,b = map(int, input().split())
end_i, end_j = a - 1, b - 1

arr = [list(map(int, input().split())) for _ in range(H)]

def bfs(i, j, cnt):
    global K
    if i == end_i and j == end_j:
        return cnt
    for move in [(1, 0), (0, 1), (-1, 0), (0, -1), (1, 1)]:
        if move == (1, 1):


