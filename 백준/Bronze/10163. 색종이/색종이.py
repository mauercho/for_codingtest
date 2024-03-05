import sys
input = sys.stdin.readline

N = int(input())

matrix = [[0] * 1001 for _ in range(1001)]
for cnt in range(1, N + 1):
    a, b, width, height = map(int, input().split())
    for col in range(b, b + height):
        matrix[col][a:a+width] = [cnt] * width

stack = [0] * (N + 1)
for row in matrix:
    for num in row:
        if num:
            stack[num] += 1

for i in range(1, N + 1):
    print(stack[i])