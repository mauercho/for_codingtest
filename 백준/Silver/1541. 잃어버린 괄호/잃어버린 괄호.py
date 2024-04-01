import sys

input = sys.stdin.readline

def real(num):
    sum_val = 0
    for s in num:
        sum_val = sum_val * 10 + int(s)
    return sum_val

def get_ans(string):
    new_lst = string.split('+')
    new_ans = real(new_lst[0])
    for i in range(1, len(new_lst)):
        new_ans += real(new_lst[i])
    return new_ans

lst = input().rstrip().split('-')

ans = get_ans(lst[0])
for idx in range(1, len(lst)):
    ans -= get_ans(lst[idx])
print(ans)

