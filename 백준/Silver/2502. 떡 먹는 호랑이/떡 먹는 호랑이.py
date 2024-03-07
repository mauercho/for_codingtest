def check(a_cnt, b_cnt):
    for a in range(1, K + 1):
        for b in range(a, K + 1):
            if (a * a_cnt) + (b * b_cnt) == K:
                print(a)
                print(b)
                return
            if (a * a_cnt) + (b * b_cnt) > K:
                break

dp_a = [0] * 31
dp_b = [0] * 31

dp_a[1] = 1
dp_a[3] = 1
dp_a[4] = 1
dp_b[2] = 1
dp_b[3] = 1
dp_b[4] = 2
for i in range(5, 31):
    dp_a[i] = dp_a[i - 1] + dp_a[i - 2]
    dp_b[i] = dp_b[i - 1] + dp_b[i - 2]

D, K = map(int, input().split())
a_cnt = dp_a[D]
b_cnt = dp_b[D]

check(a_cnt, b_cnt)
