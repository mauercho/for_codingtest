import sys
EPS = 1e-12
input = sys.stdin.readline
N = int(input())

if N == 0:
    print(0)
else:
    arr = []
    for _ in range(N):
        arr.append(int(input()))


    arr.sort()
    cut = N * 15 / 100
    cut = int(round(cut + EPS, 0))
    new_lst = arr[cut:len(arr)-cut]
    print(int(round(sum(new_lst)/len(new_lst) + EPS, 0)))
