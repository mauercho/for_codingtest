from collections import deque
import sys
commands = ["push_back", "push_front", "front", "back", "size", "empty", "pop_front", "pop_back"]

input = sys.stdin.readline
N = int(input())
q = deque()
for _ in range(N):
    command = list(input().rstrip().split())
    if len(command) == 1:
        if command[0] == commands[2]:
            if len(q) == 0:
                print(-1)
            else:
                print(q[0])
        elif command[0] == commands[3]:
            if len(q) == 0:
                print(-1)
            else:
                print(q[-1])
        elif command[0] == commands[4]:
            print(len(q))
        elif command[0] == commands[5]:
            if len(q) == 0:
                print(1)
            else:
                print(0)
        elif command[0] == commands[6]:
            if len(q) == 0:
                print(-1)
            else:
                print(q.popleft())
        elif command[0] == commands[7]:
            if len(q) == 0:
                print(-1)
            else:
                print(q.pop())
    else:
        if command[0] == commands[0]:
            q.append(command[1])
        else:
            q.appendleft(command[1])
            
            


