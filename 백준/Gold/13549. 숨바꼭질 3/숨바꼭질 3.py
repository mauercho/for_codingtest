# from collections import deque
from heapq import heappop, heappush

def bfs():
    # q = deque()
    q = []
    heappush(q, (0, N))
    visited[N] = True
    while q:
        cnt, x = heappop(q)
        if x == K:
            return cnt
        while 0 < 2 * x <= 100000 and not visited[2 * x]:
            heappush(q, (cnt, 2 * x))
            visited[2 * x] = True
        if 0 <= x - 1 <= 100000 and not visited[x - 1]:
            heappush(q, (cnt + 1, x - 1))
            visited[x - 1] = True
        if 0 <= x + 1 <= 100000 and not visited[x + 1]:
            heappush(q, (cnt + 1, x + 1))
            visited[x + 1] = True
        
N, K = map(int, input().split())
visited = [False] * 100001
print(bfs())