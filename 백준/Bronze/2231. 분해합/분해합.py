N = int(input())
is_True = False
for i in range(1, N + 1):
    string = str(i)
    sum_val = 0
    for mem in string:
        sum_val += int(mem)
    sum_val += i
    if sum_val == N:
        is_True = True
        break
if not is_True:
    print(0)
else:
    print(i)
