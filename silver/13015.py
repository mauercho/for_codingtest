dp = [-1] * 101
dp[2] = 1

def get_width(n):
    if dp[n] != -1:
        return dp[n]
    dp[n] = get_width(n - 1) + 2
    return dp[n]

N = int(input())

width = get_width(N)
lst = []
first_width = 1
lst.append("*" * N + " " * width + "*" * N)
width -= 2
for _ in range(N - 2):
    lst.append(" " * first_width + "*" + " " * (N -2) + "*" + " " * width + "*" + " " * (N -2) + "*")
    width -= 2
    first_width += 1
lst.append(" " * first_width + "*" + " " * (N - 2) + "*" + " " * (N - 2) + "*")
first_width -= 1
width += 2
for _ in range(N - 2):
    lst.append(" " * first_width + "*" + " " * (N -2) + "*" + " " * width + "*" + " " * (N -2) + "*")
    width += 2
    first_width -= 1
lst.append("*" * N + " " * width + "*" * N)
for line in lst:
    print(line)