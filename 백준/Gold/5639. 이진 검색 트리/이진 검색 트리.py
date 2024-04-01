import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def do_func(lst):
    if len(lst) == 0:
        return
    if len(lst) == 1:
        print(lst[0])
        return
    mid = lst[0]
    idx = 1
    while idx < len(lst):
        if lst[idx] > mid:
            break
        idx += 1
    if idx == len(lst): # 나뉘는 구간이 없는 거임.
        do_func(lst[1:len(lst) + 1])
    else:
        do_func(lst[1:idx])
        do_func(lst[idx:len(lst) + 1])
    print(mid)


arr = []
while True:
    try:
        n = int(input())
        arr.append(n)
    except:
        break

do_func(arr)