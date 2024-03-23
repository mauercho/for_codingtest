import sys

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    mul_val = 1
    N = int(input())
    d = dict()
    for _ in range(N):
        a, b = input().rstrip().split()
        if b in d:
            d[b] += 1
        else:
            d[b] = 1
    for k, v in d.items():
        mul_val *= (v + 1)

    print(mul_val - 1)