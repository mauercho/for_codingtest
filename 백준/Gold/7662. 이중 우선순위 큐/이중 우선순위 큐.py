import sys

from heapq import heappop, heappush

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    n = int(input())
    pq_min = []
    pq_max = []
    cnt = 0
    check = [False] * n
    for i in range(n):
        a, b = input().split()
        if a == 'I':
            heappush(pq_min, (int(b), i))
            heappush(pq_max, (-int(b), i)) # 나중에 마이너스를 빼줘야 함.
            cnt += 1
        else:
            if cnt == 0:
                continue
            if int(b) == -1: # 최솟값 빼기
                thing = heappop(pq_min)
                check[thing[1]] = True
            else:
                thing = heappop(pq_max)
                check[thing[1]] = True
            cnt -= 1
        while pq_min and check[pq_min[0][1]]:
            heappop(pq_min)
        while pq_max and check[pq_max[0][1]]:
            heappop(pq_max)
    if cnt == 0:
        print("EMPTY")
    else:
        print(-heappop(pq_max)[0], heappop(pq_min)[0])

