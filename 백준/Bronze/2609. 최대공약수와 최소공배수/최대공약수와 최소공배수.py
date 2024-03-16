import math
a, b = map(int, input().split())

if a > b:
    a, b = b, a

# b가 큼.

arr = []
for i in range(1, int(math.sqrt(a)) + 1):
    if a % i == 0:
        arr.append(i)
length = len(arr)
for x in range(length):
    arr.append(a // arr[x])

gcd = 1
for mem in arr:
    if b % mem == 0:
        gcd = max(gcd,  mem)

for i in range(1, a + 1, 1):
    if (b * i) % a == 0:
        lsm = b * i
        break

print(gcd)
print(lsm)