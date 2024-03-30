import sys

input = sys.stdin.readline

def check(i):
    x = 0
    while x < n:
        if string[i + 1 + 2 * x] != 'O':
            return False
        if string[i + 2 + 2 * x] != 'I':
            return False
        x += 1
    return True

def check_2():
    global i

    if string[i] == 'O' and string[i + 1] == 'I':
        i += 2
        return True
    else:
        return False


n = int(input())
l = int(input())
length = 2 * n + 1
string = input().rstrip()

i = 0
cnt = 0


while i <= l - length:
    if string[i] == 'I':
        if check(i):
            cnt += 1
            i += length
            while i + 1 < l and check_2():
                cnt += 1
        else:
            i += 1
    else:
        i += 1

print(cnt)