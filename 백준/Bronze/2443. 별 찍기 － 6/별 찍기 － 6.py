N = int(input())

for i in range(N - 1, -1, -1):
    string = "*" * (2 * i + 1)
    print(string.center(2 * (N - 1) + 1).rstrip()) 