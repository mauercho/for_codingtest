import sys
from collections import deque

input = sys.stdin.readline

N = int(input())

arr = []
for _ in range(N):
    arr.append(int(input()))

q = deque(i for i in range(1, N + 1))

move = deque()
stack = []

next = 0
can = False
while True:
    if q:
        stack.append(q.popleft())
        move.append('+')
    else:
        break

    while stack and arr[next] == stack[-1]:
        move.append('-')
        stack.pop()
        next += 1
        if next == N:
            can = True
            break
if can:
    print(*move, sep='\n')
else:
    print("NO")




