import sys
import heapq
input = sys.stdin.readline

N = int(input())

heap = []
for _ in range(N):
    heapq.heappush(heap, int(input().rstrip()))

ans = 0
while len(heap) != 1:
    one = heapq.heappop(heap)
    two = heapq.heappop(heap)
    sum_val = one + two
    ans += sum_val
    heapq.heappush(heap, sum_val)

print(ans)
