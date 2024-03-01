N = int(input())
up = (N + 1) // 2
down = N // 2

if N == 1:
    print("*")
else:
    for _ in range(N):
        print("* " * up)
        print(" *" * down)