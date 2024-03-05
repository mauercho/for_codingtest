N = int(input())

for i in range(1, N + 1):
    string = ""
    string += '*' * i
    string += ' ' * (2 * N - 2 * i)
    string += '*' * i
    print(string)

for i in range(N - 1, 0, -1):
    string = ""
    string += '*' * i
    string += ' ' * (2 * N - 2 * i)
    string += '*' * i
    print(string)