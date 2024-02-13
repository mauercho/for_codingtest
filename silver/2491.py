import math

N = int(input())
arr = list(map(int, input().split()))

up = -math.inf
down = -math.inf

up_cnt = 1
down_cnt = 1
if len(arr) == 1:
    print(1)
else:
    for i in range(len(arr) - 1):
        if arr[i] < arr[i + 1]:
            up_cnt += 1
            down = max(down_cnt, down)
            down_cnt = 1
            
        elif arr[i] > arr[i + 1]:
            down_cnt += 1
            up = max(up_cnt, up)
            up_cnt = 1
        else:
            up_cnt += 1
            down_cnt += 1
            down = max(down_cnt, down)
            up = max(up_cnt, up)

    if i == len(arr) - 2:
        down = max(down_cnt, down)
        up = max(up_cnt, up)

    print(max(up, down))
