import sys
from itertools import combinations
from collections import deque
input = sys.stdin.readline


n, m = map(int, input().split())
ans = 0
zero_cnt = n * m
zero_pos = []
virus_pos = []
wall_pos = []
arr =[]
for i in range(n):
    lst = list(map(int, input().split()))
    arr.append(lst)
    for j in range(m):
        if lst[j] == 0:
            zero_pos.append((i, j))
        elif lst[j] == 1:
            wall_pos.append((i, j))
            zero_cnt -= 1
        else:
            virus_pos.append((i, j))
            zero_cnt -= 1

for mem in combinations(zero_pos, 3): # 여기서 3개씩 걸러지는데 ?
    temp_cnt = zero_cnt # 변수 복사
    temp_cnt -= 3
    temp_arr = [x[:] for x in arr]
    q = deque()
    flag = True
    for pos in mem:
        temp_arr[pos[0]][pos[1]] = 1
    for pos in virus_pos:
        q.append(pos)
    while q:
        temp_i, temp_j = q.popleft()
        for move in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            mi = temp_i + move[0]
            mj = temp_j + move[1]
            if not (0 <= mi < n and 0 <= mj < m):
                continue
            if temp_arr[mi][mj] == 0:
                temp_arr[mi][mj] = 2
                temp_cnt -= 1
                q.append((mi, mj))
        if ans > temp_cnt:
            flag = False
            break
    if not flag:
        continue
    ans = max(ans, temp_cnt)

print(ans)
