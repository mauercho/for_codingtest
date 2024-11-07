import sys
import heapq

input = sys.stdin.readline

n, k = map(int, input().split())

arr = []
heap_arr = []
for i in range(n):
    lst = list(map(int, input().split()))
    for j in range(n):
        if lst[j] > 0:
            heapq.heappush(heap_arr, (lst[j], i, j))
    arr.append(lst)

second, x, y = map(int, input().split())

time = 0
while heap_arr and time < second:
    temp_arr = []
    while heap_arr:
        virus, i, j = heapq.heappop(heap_arr)
        for move in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            ni = i + move[0]
            nj = j + move[1]
            if not (0 <= ni < n and 0 <= nj < n):
                continue
            if arr[ni][nj] != 0:
                continue
            arr[ni][nj] = virus
            temp_arr.append((virus, ni, nj))
    for mem in temp_arr:
        heapq.heappush(heap_arr, mem)
    time += 1

print(arr[x - 1][y - 1])
