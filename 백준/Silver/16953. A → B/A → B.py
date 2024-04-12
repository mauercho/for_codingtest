import sys
from collections import deque
input = sys.stdin.readline

def bfs(start, end):
    q = deque()
    q.append((start, 1))
    while q:
        pos, cnt = q.popleft()
        if pos == end:
            return cnt
        if pos * 2 > end or pos == 0:
            continue
        else:
            q.append((pos * 2, cnt + 1))
        if pos * 10 + 1 > end:
            continue
        else:
            q.append((pos * 10 + 1, cnt + 1))
    return -1


a, b = map(int, input().split())

print(bfs(a, b))