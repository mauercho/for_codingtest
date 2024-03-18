from collections import deque
import sys

input = sys.stdin.readline
T = int(input())

for _ in range(T):
    N, M = map(int, input().split())
    q = deque() 
    for i, mem in enumerate(list(map(int, input().split()))):
        q.append((mem, i))
    cnt = 1
    while q:
        max_val = max(q)[0]
        temp = q.popleft()
        if temp[0] == max_val:
            if temp[1] == M:
                break
            cnt += 1
        else:
            q.append(temp)
    print(cnt)

    




