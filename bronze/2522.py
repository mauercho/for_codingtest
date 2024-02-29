N = int(input())

for i in range(N):
    print(("*" * (i + 1)).rjust(N))
for i in range(N - 1, 0, -1):
    print(("*" * (i)).rjust(N))