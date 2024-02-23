import sys

sys.setrecursionlimit(100000)

def find_depth(N):
    dep = 1
    while 2 ** dep < N:
        dep += 1
    return dep

def print_arr(idx):
    if idx >= 2 ** depth:
        return
    print_arr(idx * 2)
    print_arr(idx * 2 + 1)
    print(num[idx], end = ' ')


def create_tree(mid_idx, width):
    if width == 0:
        return
    width = width // 2
    create_tree(mid_idx - width, width)
    num[mid_idx + 1] = arr[mid_idx]
    create_tree(mid_idx + width, width)

N = int(input())

arr = list(map(int, input().split()))
arr.remove(-1)
depth = find_depth(N)
num = [0] * (2 ** depth)
num_change = int(input())
arr.append(num_change)
arr.sort()
div = N // 2 + 1
idx = 0
create_tree(N // 2, div)
print(num)