N = int(input())

cnt = 1
mul = 1
while N > cnt:
    cnt += 6 * mul
    mul += 1

print(mul)