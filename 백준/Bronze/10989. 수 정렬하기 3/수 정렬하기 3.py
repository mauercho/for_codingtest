import sys

input = sys.stdin.readline

lst = [0] * 10001
T = int(input())
for tc in range(T):
    x = int(input())
    lst[x] += 1

for i in range(len(lst)):
    while lst[i] > 0:
        print(i)
        lst[i] -= 1