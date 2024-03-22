import sys

input = sys.stdin.readline

N, M = map(int, input().split())
sum_arr = [0] * (N)
for i, mem in enumerate(list(map(int, input().split()))):
    if i == 0:
        sum_arr[i] = mem
    else:
        sum_arr[i] = sum_arr[i - 1] + mem

for _ in range(M):
    a, b = map(lambda x: int(x) - 1, input().split())
    if a != 0:
        print(sum_arr[b] - sum_arr[a - 1])
    else:
        print(sum_arr[b])