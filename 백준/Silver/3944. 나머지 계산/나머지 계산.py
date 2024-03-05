import sys

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    B, D = input().split()
    B = int(B)
    result = sum(map(int, list(D)))
    print(result % (B -1))