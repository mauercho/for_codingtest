import math
row, col = map(int, input().split())

N = int(input())
ans = -math.inf

for _ in range(N):
    a, b = map(int, input().split())
    lst_row = []
    lst_col = []
    if a == 0:
        lst_col.append(b)     
    else:
        lst_col.append(a)
    lst_row
for i in sorted(lst_col):
    for j in sorted(lst_col):
        