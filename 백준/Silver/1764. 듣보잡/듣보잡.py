import sys

input = sys.stdin.readline
N, M = map(int, input().split())

set_1 = set()
for _ in range(N):
    set_1.add(input().rstrip())
lst = []
for _ in range(M):
    string = input().rstrip()
    if string in set_1:
        lst.append(string)

lst.sort()
print(len(lst))
print(*lst, sep='\n')
