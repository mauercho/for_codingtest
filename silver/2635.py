N = int(input())
longest_lst = []
ans = 0
for i in range(N + 1):
    arr = []
    arr.append(N)
    arr.append(i)
    gap = N - i
    prev = i
    while gap >= 0:
        arr.append(gap)
        temp = gap
        gap = prev - gap
        prev = temp
    if len(longest_lst) < len(arr):
       ans = len(arr)
       longest_lst = arr

print(ans)
print(*longest_lst)