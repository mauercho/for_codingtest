n = int(input())
lst = []
for i in range(n):
    name, korean, english, math = input().split()
    lst.append((int(korean), int(english), int(math), name))

lst.sort(key=lambda x: (-x[0], x[1], -x[2], x[3]))
for mem in lst:
    print(mem[3])
