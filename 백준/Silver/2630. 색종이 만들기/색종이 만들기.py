import sys

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

def check(i, j, w):
    color = int(arr[i][j])
    for r in range(w):
        for c in range(w):
            if int(arr[i + r][j + c]) != color:
                return -1
    return color

def recursive(n, start_i, start_j):
    global white_cnt
    global blue_cnt

    if n == 0:
        return
    if check(start_i, start_j, n) == 1:
        blue_cnt += 1
    elif check(start_i, start_j, n) == 0:
        white_cnt += 1
    else:
        recursive(n // 2, start_i, start_j)
        recursive(n // 2, start_i, start_j + n // 2)
        recursive(n // 2, start_i + n // 2, start_j)
        recursive(n // 2, start_i + n // 2, start_j + n // 2)

N = int(input())
arr = []
for _ in range(N):
    arr.append(input().split())

white_cnt = 0
blue_cnt = 0

recursive(N, 0, 0)
print(white_cnt)
print(blue_cnt)

