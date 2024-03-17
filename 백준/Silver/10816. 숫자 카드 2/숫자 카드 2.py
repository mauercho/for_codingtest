import sys

input = sys.stdin.readline

N = int(input())
d = dict()
for mem in list(map(int, input().split())):
    if mem in d:
        d[mem] += 1
    else:
        d[mem] = 1

M = int(input())
for mem in list(map(int, input().split())):
    print(d.get(mem,0), end= ' ')