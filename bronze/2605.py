
N = int(input())
arr = list(map(int, input().split()))

lst = []
for i, v in enumerate(arr):
    lst.insert(i - v, i + 1)

print(*lst)