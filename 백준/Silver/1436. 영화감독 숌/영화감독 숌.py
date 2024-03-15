N = int(input())
cnt = 0
for i in range(666, 20000000):
    if '666' in str(i):
        cnt += 1
        if N == cnt:
            print(i)
            break

