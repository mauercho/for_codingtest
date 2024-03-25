import sys

input = sys.stdin.readline

N = int(input())
max_arr = [0] * (N + 1)
arr = [0]
for _ in range(N):
    arr.append(int(input()))

if N == 1:
    print(arr[1])
else:
    max_arr[1] = arr[1]
    max_arr[2] = arr[1] + arr[2]
    for i in range(3, N + 1):
        max_arr[i] = max(max_arr[i - 2] + arr[i], arr[i - 1] + arr[i] + max_arr[i - 3])

    print(max_arr[N])