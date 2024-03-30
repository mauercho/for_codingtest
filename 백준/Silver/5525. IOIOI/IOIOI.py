import sys

input = sys.stdin.readline

N = int(input())
l = int(input())
string = input().rstrip()

ans = 0
cnt = 0
i = 0
while i < l - 2:
    if string[i:i+3] == 'IOI':
        i += 2
        cnt += 1
        if cnt == N:
            ans += 1
            cnt -= 1
    else:
        i+=1
        cnt = 0
print(ans)