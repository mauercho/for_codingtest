import sys
from collections import deque
input = sys.stdin.readline

Q = int(input())

q = deque()

def rotate_right(state):
    if state == 3:
        return 0
    else:
        return state + 1

def rotate_left(state):
    if state == 0:
        return 3
    else:
        return state - 1

state = 0
w_cnt = 0
b_cnt = 0
for _ in range(Q):
    arr = input().split()
    if len(arr) == 2:
        if arr[0] == 'push':
            if state == 0:
                q.appendleft(arr[1])
                if arr[1] == 'w':
                    w_cnt += 1
                elif arr[1] == 'b':
                    b_cnt += 1
            elif state == 1:
                if arr[1] == 'w':
                    q.appendleft(arr[1])
                    w_cnt += 1
                else:
                    if w_cnt > 0:
                        q.appendleft(arr[1])
                        b_cnt += 1
                    else:
                        pass
            elif state == 2:
                q.appendleft(arr[1])
                if arr[1] == 'w':
                    w_cnt += 1
                elif arr[1] == 'b':
                    b_cnt += 1
            elif state == 3:
                if arr[1] == 'w':
                    q.appendleft(arr[1])
                    w_cnt += 1
        elif arr[0] == 'rotate':
            if arr[1] == 'l':
                state = rotate_left(state)
                if state == 1:
                    while q and q[-1] == 'b':
                        q.pop()
                        b_cnt -= 1
                elif state == 3:
                    while q and q[0] == 'b':
                        q.popleft()
                        b_cnt -= 1
            elif arr[1] == 'r':
                state = rotate_right(state)
                if state == 1:
                    while q and q[-1] == 'b':
                        q.pop()
                        b_cnt -= 1
                elif state == 3:
                    while q and q[0] == 'b':
                        q.popleft()
                        b_cnt -= 1
        elif arr[0] == 'count':
            if arr[1] == 'b':
                print(b_cnt)
            else:
                print(w_cnt)
    else: # pop
        if q:
            a = q.pop()
            if a == 'w':
                w_cnt -= 1
            elif a == 'b':
                b_cnt -= 1
            if state == 1:
                while q and q[-1] == 'b':
                        q.pop()
                        b_cnt -= 1
            elif state == 3:
                while q and q[0] == 'b':
                        q.popleft()
                        b_cnt -= 1