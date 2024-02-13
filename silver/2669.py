arr = [[0] * 101 for _ in range(101)]
for _ in range(4):
    y_low, x_low, y, x = map(int, input().split())
    if y < y_low:
        y, y_low = y_low, y
    if x < x_low:
        x, x_low = x_low, x
    for i in range(y_low, y):
        for j in range(x_low, x):
            arr[i][j] = 1
    
cnt = 0
for i in range(101):
    for j in range(101):
        if arr[i][j] == 1:
            cnt += 1
print(cnt)
