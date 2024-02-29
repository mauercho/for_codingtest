dp = [-1] * 101
dp[1] =1
def make(n):
    if dp[n] != -1:
        return dp[n]
    
    dp[n] = make(n - 1) + 4
    return dp[n]

def recursive(n):
    if n == 1:
        return ["*"]
    width = make(n)
    prev = recursive(n - 1)
    lst = []
    
    lst.append("*" * width)
    lst.append("*" + " " * (width - 2) + "*")
    for line in prev:
        string = ""
        string += "* " + line + " *"
        lst.append(string)
    lst.append("*" + " " * (width - 2) + "*")
    lst.append("*" * width)
        
    return lst

N = int(input())

print_lst = recursive(N)
for line in print_lst:
    print(line)
