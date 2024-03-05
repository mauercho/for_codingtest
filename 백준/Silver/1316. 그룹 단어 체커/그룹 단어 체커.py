T = int(input())
sum_val = 0
for _ in range(T):
    arr = list(input())
    empty_arr = []
    add = 1
    for i in range(len(arr)):
        if not (arr[i] in empty_arr):
            empty_arr.append(arr[i])
        else:
            if arr[i - 1] != arr[i]:
                add = 0
    sum_val += add
print(sum_val)
