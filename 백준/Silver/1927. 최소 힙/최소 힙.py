import sys
from heapq import heappop, heappush
input = sys.stdin.readline

N = int(input())
pq = []

for _ in range(N):
    a = int(input())
    if a== 0:
        if not pq:
            print(0)
        else:
            print(heappop(pq))
    else:
        heappush(pq, a)
