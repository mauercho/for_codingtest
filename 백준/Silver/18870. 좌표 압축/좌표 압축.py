import sys

input = sys.stdin.readline


N = int(input())
arr = list(map(int, input().split()))
sort_arr = sorted(list(set(arr)))
d =dict()
for i,v in enumerate(sort_arr):
    if v not in d:
        d[v] = i

for mem in arr:
    print(d[mem], end = ' ')