import sys

input = sys.stdin.readline

def get_ans(val):
    cnt = 0
    for mem in arr:
        if mem >= val:
            cnt += mem // val
    return cnt

def binary_search():
    global ans
    start = 1
    end = max(arr)
    while start <= end:
        mid = (start + end) // 2
        if get_ans(mid) >= N:
            start = mid + 1
            ans = max(ans, mid)
        else:
            end = mid - 1


    

K, N = map(int, input().split())
arr = []
for _ in range(K):
    arr.append(int(input()))
ans = 0
binary_search()
print(ans)