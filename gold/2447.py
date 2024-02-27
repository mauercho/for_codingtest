import sys

sys.setrecursionlimit(10 **6)

N = int(input())

def recursive(i, j, N):
    if N == 1:
        arr[i][j] = '*'
    for a in range(3):
        for b in range(3):
            if a == 1 and b == 1:
                continue
            recursive(i + a * (N // 3), j + b * (N // 3), N // 3)
            
arr = [[' '] * (N) for _ in range(N)]

recursive(0, 0, N)

for i in range(N):
    print(*arr[i])

print(arr)