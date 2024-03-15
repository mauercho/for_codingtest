N = int(input())
dp =[0] * (N + 1)
dp[0] = 1
for i in range(1, N + 1):
    dp[i] = dp[i - 1] * i

string = str(dp[N])
cnt = 0
string = string[::-1]
for i in range(len(string)):
    if string[i] == '0':
        cnt += 1
    else:
        break
print(cnt)