import sys
from itertools import product

input = sys.stdin.readline

num = int(input())
length = len(str(num))


N = int(input())
number = ['0','1','2','3','4','5','6','7','8','9']

if N != 0:
    for mem in input().rstrip().split():
        number.remove(mem)


num_lst = []
for k in range(1, length + 2):
    for mem in product(number, repeat = k):
        num_lst.append(int((''.join(mem))))
ans = float('inf')

for mem in num_lst:
    if num > mem:
        compare = num - mem
    else:
        compare = mem - num
    ans = min(ans, compare + len(str(mem)))

if num > 100:
    compare = num - 100
else:
    compare = 100 - num
ans = min(ans, compare)

print(ans)