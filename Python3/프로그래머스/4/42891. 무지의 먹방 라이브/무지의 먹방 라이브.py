from heapq import heappush, heappop


def solution(food_times, k):
    if sum(food_times) <= k:
        return -1
    heap = []
    n = len(food_times)
    previous = 0
    least_num = 0
    for i, food in enumerate(food_times):
        heappush(heap, (food, i + 1))
    while heap:
        diff = (heap[0][0] - previous) * n
        if k >= diff:
            k -= diff
            previous = heappop(heap)[0]
            n -= 1
        else:
            heap.sort(key=lambda x: x[1])
            return heap[k % n][1]
                
    return -1