from itertools import permutations

n = int(input())
ans_min =1000000001
ans_max= -1000000001
def cal(a, b, oper):
    if oper == '+':
        return a + b
    elif oper == '-':
        return a - b
    elif oper == '*':
        return a * b
    else:
        if a < 0:
            return (-1) * (a * (-1) // b)
        else:
            return a // b

arr = list(map(int, input().split()))
plus, minus, mul, div = map(int, input().split())
overlap = set()

lst = tuple()
for _ in range(plus):
    lst += ('+', )
for _ in range(minus):
	lst += ('-', )
for _ in range(mul):
	lst += ('*', )
for _ in range(div):
	lst += ('/', )

for mem in permutations(lst, n - 1):
    string = ''.join(mem)
    if string in overlap:
        continue
    overlap.add(string)
    num = arr[0]
    flag = True
    for j in range(n - 1):
        num = cal(num, arr[j + 1], mem[j])
        if num >= 1000000001:
            flag = False
            break
        elif num <= -1000000001:
            flag = False
            break
    if flag:
        ans_max = max(ans_max, num)
        ans_min = min(ans_min, num)

print(ans_max)
print(ans_min)
