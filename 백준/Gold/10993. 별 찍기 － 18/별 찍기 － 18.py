width_dp = [-1] * 11
width_dp[1] = 1
def get_max_width(N):
    if width_dp[N] == -1:
        width_dp[N] = 2 * get_max_width(N - 1) + 3
    return width_dp[N]


height_dp = [-1] * 11
height_dp[1] = 0 

def get_height(N):
    if height_dp[N] == -1:
        height_dp[N] = 2 * get_height(N - 1) + 1
    return height_dp[N]

def recursive(n):
    if n == 1:
        return ["*"]
    prev = recursive(n - 1)
    lst = []
    height = get_height(n)
    if n % 2 == 0:   # 아래로 내려가야함.
        cnt_width = 1
        lst.append("*" * get_max_width(n))
        for line in prev:
            string = "" 
            string += " " * cnt_width + "*" + " " * ((get_max_width(n) - 2 - 2 * cnt_width - len(line)) // 2) + line + " " * ((get_max_width(n) - 2 - 2 * cnt_width - len(line)) // 2) + "*" + " " * cnt_width
            cnt_width += 1
            lst.append(string)
        for _ in range(height_dp[n] - 1):
            string = ""
            string += " " * cnt_width + "*" + " " * (get_max_width(n) - 2 * cnt_width - 2) + "*" + " " * cnt_width
            cnt_width += 1
            lst.append(string)
        string = ""
        string += " " * cnt_width + "*" + " " * cnt_width
        lst.append(string)

    else:  #위로 올려야함.
        width = (get_max_width(n) - 1) // 2
        for i in range(height):
            string = ""
            if i == 0:
                string += " " * width + "*" + " " * width 
                width -= 1
            else:
                string += " " * width + "*" + " " * (i * 2 - 1) + "*" + " " * width
                width -= 1
            lst.append(string)
        for line in prev:
            string = ""
            string += " " * width + "*" + " " * ((get_max_width(n) - len(line) - 2 - width * 2) // 2) + line  + " " * ((get_max_width(n) - len(line) - 2 - width * 2) // 2) + "*" + " " * width
            width -= 1
            lst.append(string)
        lst.append("*" * get_max_width(n))
    return lst

N = int(input())
new_lst = recursive(N)
for line in new_lst:
    print(line.rstrip())