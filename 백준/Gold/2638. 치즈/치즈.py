import sys
from collections import deque

input = sys.stdin.readline

def do_minus_change(arr):
    q = deque()
    q.append((0, 0))    
    arr[0][0] = -1
    while q:
        i, j = q.popleft()
        for ni, nj in [(1,0), (0,1), (-1, 0), (0, -1)]:
            di = i + ni
            dj = j + nj
            if 0 <= di < N and 0 <= dj < M and arr[di][dj] == 0:
                arr[di][dj] = -1
                q.append((di, dj))

def near_minus(i, j, arr):
    cnt = 0
    if arr[i + 1][j] == -1:
        cnt += 1 
    if arr[i][j - 1] == -1:
        cnt += 1
    if arr[i - 1][j] == -1:
        cnt += 1 
    if arr[i][j + 1] == -1:
        cnt += 1
    
    if cnt >= 2:
        return True
    else:
        return False


N, M = map(int,input().split())



arr = []
for _ in range(N):
    arr.append(list(map(int, input().split())))

do_cnt = 0
one_cnt = sum(map(sum, arr))
while True:
    copy_arr = [list[:] for list in arr]
    do_minus_change(copy_arr)
    if one_cnt == 0:
        break
    do_cnt += 1
    lst_for_cheese = []
    for i in range(N):
        for j in range(M):
            if copy_arr[i][j] == 1 and near_minus(i, j, copy_arr):
                one_cnt -= 1
                lst_for_cheese.append((i, j))
    if one_cnt == 0:
        break
    for i, j in lst_for_cheese:
        arr[i][j] = 0
print(do_cnt)
