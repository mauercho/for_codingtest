import math
import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

def side_return(i):
    if i == 0:
        return (1,2,3,4)
    elif i == 1:
        return (0,2,4,5)
    elif i == 2:
        return (0,1,3,5)
    elif i == 3:
        return (0,2,4,5)
    elif i == 4:
        return (0,1,3,5)
    elif i == 5:
        return (1,2,3,4)

def get_index_return_max(idx, arr):
    a,b,c,d = side_return(idx)
    return max(arr[a],arr[b],arr[c],arr[d])

def recursive(num, cnt): # 이걸로 재귀 돌거임.



N = int(input())

dices = []
ans = -math.inf
for _ in range(N):
    dices.append(list(map(int, input().split())))

sum_val = 0
for i in range(6): # dice[0]의 여섯 가지 칸.
    bottom_dice_top_num = dices[0][i]
    recursive(bottom_dice_top_num, 1)


