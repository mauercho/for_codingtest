N = int(input())

arr = list(map(int, input().split()))
max_val = max(arr)
sum_val = 0
for mem in arr:
    sum_val += mem / max_val * 100

print(sum_val / N)