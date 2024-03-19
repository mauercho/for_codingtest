N, r, c = map(int, input().split())

base = 0
while N != 0:
    if r >= 2 ** (N - 1):
        base += 2 ** (2 * N - 1)
        r -= 2 ** (N - 1)
        if c >= 2 ** (N - 1):
            base += 2 ** (2 *N - 2)
            c -= 2 ** (N - 1)
    else:
        if c >= 2 ** (N - 1):
            base += 2 ** (2 *N - 2)
            c -= 2 ** (N - 1)
    
    N -= 1

print(base)
