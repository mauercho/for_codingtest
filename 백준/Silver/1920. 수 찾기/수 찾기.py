def check(target):
    start = 0
    end = N - 1
    while start <= end:
        mid = (start + end) // 2
        if arr[mid] == target:
            return True
        elif arr[mid] < target:
            start = mid + 1
        else:
            end = mid - 1


    return False

N = int(input())
arr = list(map(int, input().split()))
arr.sort()
M = int(input())
for mem in list(map(int, input().split())):
    if check(mem):
        print(1)
    else:
        print(0)
