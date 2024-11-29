n, c = map(int, input().split())

arr = []
for _ in range(n):
    arr.append(int(input()))
arr.sort()
start = 1
end = arr[-1] - arr[0]

# print("start")
while start <= end:
    mid = (start + end) // 2
    cnt = 1
    s = arr[0]
    # print("check", mid)
    for mem in arr[1:]:
        if s + mid <= mem:
            cnt += 1
            # print(mem, s + mid)
            s = mem
    if cnt >= c:
        ans = mid
        start = mid + 1
    else:
        end = mid - 1

print(ans)
