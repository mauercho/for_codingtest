import sys
from itertools import combinations
input = sys.stdin.readline

def check(first, second, third):
    global ans

    cnt = 0

    for k in range(4):
        if first[k] != second[k]:
            cnt +=1
        if first[k] != third[k]:
            cnt += 1
        if second[k] != third[k]:
            cnt += 1
    ans = min(ans, cnt)

T = int(input())
for _ in range(T):
    N = int(input())
    arr = input().split()
    if N > 32:
        print(0)
    else:
        cnt = 0
        ans = float('inf')
        for combi in combinations(arr, 3):
            check(combi[1], combi[0], combi[2])
        print(ans)