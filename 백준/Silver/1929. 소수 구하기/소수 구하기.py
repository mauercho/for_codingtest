import math

def is_prime(num):
    end_num = int(math.sqrt(num))
    if num == 1:
        return False
    for i in range(2, end_num + 1):
        if num % i == 0:
            return False
    return True

M, N = map(int, input().split())

for i in range(M, N + 1):
    if is_prime(i):
        print(i)