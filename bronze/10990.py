N = int(input())
width = 2 * N -1
for i in range(N):
    if i == 0:
        string = "*"
    else:
        string = "*" + " " * (2 * i - 1) + '*'
    print(string.center(width).rstrip())
    