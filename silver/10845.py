import sys
from collections import deque

input = sys.stdin.readline
N = int(input())
cnt = 0
q = deque()
for _ in range(N):
    arr = list(input().split())
    if len(arr) == 2:
        q.append(arr[1])
        cnt += 1
    else:
        if arr[0] == 'pop':
            if q:
                print(q.popleft())
                cnt -= 1
            else:
                print(-1)
        elif arr[0] == 'size':
            print(cnt)
        elif arr[0] == 'empty':
            if q:
                print(0)
            else:
                print(1)
        elif arr[0] == 'front':
            if q:
                print(q[0])
            else:
                print(-1)
        elif arr[0] == 'back':
            if q:
                print(q[-1])
            else:
                print(-1)

