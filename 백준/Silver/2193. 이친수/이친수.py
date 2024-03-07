N = int(input())
dp_end_0 = [0] * 91
dp_end_1 = [0] * 91

dp_end_1[1] = 1
dp_end_0[2] = 1
for i in range(3, 91):
    dp_end_1[i] = dp_end_0[i - 1]
    dp_end_0[i] = dp_end_1[i - 1] + dp_end_0[i - 1]

print(dp_end_0[N] + dp_end_1[N])