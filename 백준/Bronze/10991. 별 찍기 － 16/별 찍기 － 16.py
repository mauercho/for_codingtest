N = int(input())

width = 2 * N - 1

for i in range(N):
    if i == 0:
        string = '*'
    else:
        string = ''
        cnt = i
        string += "*"
        for _ in range(cnt):
            string += " *"
    print(string.center(width).rstrip())
    