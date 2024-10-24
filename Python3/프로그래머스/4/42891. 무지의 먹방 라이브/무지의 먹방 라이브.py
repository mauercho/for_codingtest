import heapq

def solution(food_times, k):
    if sum(food_times) <= k: # 무조건 음식 다먹는 수
        return -1
    answer = 2
    q = []  # 무조건 그거있음.
    length = len(food_times)
    for i in range(len(food_times)):
        heapq.heappush(q, (food_times[i], i + 1))
    prev = 0
    while k > length * (q[0][0] - prev):
        k -= length *  (q[0][0] - prev) 
        prev = q[0][0]
        heapq.heappop(q)
        length -= 1
    # 여기서 다 털음.
    lst  = sorted(q, key= lambda x : x[1])
    answer = lst[k % length][1]
    return answer