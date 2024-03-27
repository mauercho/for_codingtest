import sys
from heapq import heappush, heappop

input = sys.stdin.readline

pq = []
N = int(input())
for _ in range(N):
    a = int(input())
    if a == 0:
        if pq:
            print(-heappop(pq))
        else:
            print(0)
    else:
        heappush(pq, -a)