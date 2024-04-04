import sys

input = sys.stdin.readline

def calculate(M, N, x, y):
    K = x
    while K <= M * N:
        if (K - x) % M == 0 and (K - y) % N == 0:
            return K
        K += M
    return -1


N = int(input())

for _ in range(N):
    M, N, x, y = map(int, input().split())

    print(calculate(M, N, x, y))