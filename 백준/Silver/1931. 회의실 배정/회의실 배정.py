import sys

input = sys.stdin.readline

n = int(input())
arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))
cnt = 0
arr.sort(key= lambda x:(x[1],x[0]))
end = 0
for mem in arr:
    if mem[0] >= end:
        cnt += 1
        end = mem[1]
print(cnt)

