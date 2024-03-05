dp = [-1] * 101

dp[1] = 1

def get_width(n):
    if dp[n] != -1:
        return dp[n]
    dp[n] = get_width(n - 1) + 4
    return dp[n]

def recursive(n):
    if n == 1:
        return ["*"]
    if n == 2:
        return ["*****", "*    ", "* ***", "* * *", "* * *", "*   *", "*****"]
    width = get_width(n)
    prev = recursive(n - 1)
    new_lst = []
    new_lst.append("*" * width)
    new_lst.append("*" + " " * (width - 1))
    for i in range(len(prev)):
        if i == 0:
            new_lst.append("* " + prev[i] + "**")
        else:
            new_lst.append("* " + prev[i] + " *")
    new_lst.append("*" + " " * (width - 2) + "*")
    new_lst.append("*" * width)
    return new_lst



N = int(input())

lst = recursive(N)
for line in lst:
    print(line.rstrip())

