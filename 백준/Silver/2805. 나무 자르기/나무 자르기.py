import sys
input = sys.stdin.readline

N, M = map(int, input().split()) 

arr = list(map(int, input().split()))
end = max(arr)
start = 0
ans = 0
while start <= end:
    mid = (start + end) // 2
    sum_val = 0
    for mem in arr:
        sum_val += max(0, mem - mid)
    if M <= sum_val:
        ans = mid
        start = mid + 1
    else:
        end = mid - 1

print(ans)