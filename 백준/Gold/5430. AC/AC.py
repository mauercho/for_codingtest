import sys
import re
from collections import deque
input = sys.stdin.readline

T = int(input())

for tc in range(T):
    commands = input().rstrip()
    N = int(input())
    if N == 0:
        q = deque()
        input()
        flip = True
        flag = True
    else:
        lst = input().rstrip()
        lst = re.split('[\]\[,]', lst)
        q = deque(lst)
        q.popleft()
        q.pop() 
        flag = True
        flip = True # True 면 정 방향 popleft() 
    for command in commands:
        if command == 'R':
            if flip:
                flip = False
            else:
                flip = True
        else:
            if not q:
                print("error")
                flag = False
                break
            else:
                if flip:
                    q.popleft()
                else:
                    q.pop()
    if not flag:
        continue
    if flip:
        print("[", end='')
        print(*q, sep=',', end='')
        print("]")
    else:
        q.reverse()
        print("[", end='')
        print(*q, sep=',',end='')
        print("]")
