import sys

input = sys.stdin.readline

def side_return(i):
    if i == 0:
        return 1,2,3,4
    elif i == 1:
        return 0,2,4,5
    elif i == 2:
        return 0,1,3,5
    elif i == 3:
        return 0,2,4,5
    elif i == 4:
        return 0,1,3,5
    elif i == 5:
        return 1,2,3,4

def opposite_return(i):
    if i == 0:
        return 5
    elif i == 1:
        return 3
    elif i == 2:
        return 4
    elif i == 3:
        return 1
    elif i == 4:
        return 2
    elif i == 5:
        return 0

def get_index_return_max(idx, arr):
    a,b,c,d = side_return(idx)
    return max(arr[a],arr[b],arr[c],arr[d])


N = int(input())

dices = []
ans = 0
for _ in range(N):
    dices.append(list(map(int, input().split())))

for i in range(6): 
    bottom_dice_top_num = dices[0][i]
    sum_val = get_index_return_max(i, dices[0])
    for j in range(1, N):
        idx = ("".join(map(str, dices[j]))).index(str(bottom_dice_top_num))
        sum_val += get_index_return_max(idx, dices[j])
        bottom_dice_top_num = dices[j][opposite_return(idx)]
    else:
        ans = max(sum_val, ans)
print(ans)
