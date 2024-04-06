import sys
from heapq import heappop, heappush
from itertools import combinations
input = sys.stdin.readline

def count_0(array): # 모두 0이면 끝

    for mem in array:
        if mem.count(0) != M:
            return False
    return True

def get_distance(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

def down(array):
    for j in range(M):
        for i in range(N - 1, 0, -1):
            array[i][j] = array[i - 1][j]
    for j in range(M):
        array[0][j] = 0

def kill(pos_list, arr):
    global count
    targets = set()
    for pos in pos_list:
        pq = []
        for i in range(max(0, N - D), N):
            for j in range(M):
                if arr[i][j] == 1 and get_distance((i, j), pos) <= D:
                    heappush(pq, (get_distance((i,j), pos), j, i, j)) # 거리, 왼쪽 우선, i, j 순으로 푸시
        if pq:
            _, _, i, j = heappop(pq) # 가장 가까우면서 왼쪽에 있는 적 선택
            targets.add((i, j)) # 수정된 부분

    for t in targets: # 여러 궁수가 선택한 적들을 제거
        arr[t[0]][t[1]] = 0
        count += 1

N, M, D = map(int, input().split())

arr = []
for _ in range(N):
    arr.append(list(map(int, input().split())))
ans = 0

for mem in combinations(range(M), 3):
    count = 0
    copy_arr = [mem[:] for mem in arr]
    while True:
        pos_list = [(N, j) for j in mem]
        kill(pos_list, copy_arr)
        down(copy_arr)
        if count_0(copy_arr):
            break
    ans = max(ans, count)
print(ans)