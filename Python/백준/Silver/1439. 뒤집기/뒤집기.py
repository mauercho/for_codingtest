import sys

input = sys.stdin.readline

data = input().rstrip()
cnt1 = 0
cnt2 = 0
prev = int(data[0])
for i in range(1, len(data)):
    t = int(data[i])
    if t == prev:
        continue
    else:
        if t == 1:
            cnt1 += 1
            prev = 1
        else:
            cnt2 += 1
            prev = 0
if prev == 1:
    cnt2 += 1
else:
    cnt1 += 1

print(min(cnt1, cnt2))
