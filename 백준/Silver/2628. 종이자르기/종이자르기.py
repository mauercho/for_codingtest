import math
row, col = map(int, input().split())

N = int(input())
ans = -math.inf
lst_row = [0]
lst_col = [0]
for _ in range(N):
    a, b = map(int, input().split())
    if a == 0:
        lst_col.append(b)
    else:
        lst_row.append(b)
lst_row.append(row)
lst_col.append(col)
lst_col.sort()
lst_row.sort()

for i in range(len(lst_col) - 1):
    for j in range(len(lst_row) - 1):
        area = (lst_row[j + 1] - lst_row[j]) * (lst_col[i + 1] - lst_col[i])
        ans = max(ans, area)

print(ans)